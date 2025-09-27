/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_selected_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:21:54 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 22:06:22 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	exit_no_command_found(t_shell *shell, char *cmd)
{
	if (has_dot_slash(cmd))
	{
		if (access(cmd, F_OK) == 0)
		{
			printerr_src_msg_ln(cmd, MSG_PERM_DENIED);
			ch_exit(shell, CODE_126_PRESENT_BUT_NOT_EXECUTABLE);
		}
		else
		{
			printerr_src_msg_ln(cmd, MSG_NO_SUCH_FILE_OR_DIR);
			ch_exit(shell, CODE_127_NO_PRESENT);
		}
	}
	printerr_src_msg_ln(cmd, MSG_CMD_NOT_FOUND);
	ch_exit(shell, CODE_127_NO_PRESENT);
}

static void	exit_if_directory(t_exec *exec, const t_exec_list *current_cmd)
{
	if (is_directory(current_cmd->command_with_args[0]))
	{
		printerr_src_msg_ln(current_cmd->command_with_args[0], MSG_IS_A_DIR);
		ch_exit(exec->shell, CODE_126_PRESENT_BUT_NOT_EXECUTABLE);
	}
}

static void	execute_if_has_dot_slash(t_exec *exec, t_exec_list *current_cmd)
{
	if (has_dot_slash(current_cmd->command_with_args[0]))
	{
		execute_command(exec, ft_strdup(current_cmd->command_with_args[0]),
			&current_cmd->command_with_args);
		ch_handle_error(exec->shell, NO_MESSAGE);
	}
}

static void	execute_command_child(t_exec *exec, t_exec_list *current_cmd)
{
	char	*cmd;
	int		stat;

	if (current_cmd->command_with_args == NULL)
		ch_exit(exec->shell, SUCCESS);
	if (can_use_builtin(current_cmd->command_with_args[0]) == TRUE)
	{
		stat = execute_builtins(exec->shell, current_cmd->command_with_args);
		ch_exit(exec->shell, stat);
	}
	exit_if_directory(exec, current_cmd);
	execute_if_has_dot_slash(exec, current_cmd);
	cmd = get_command(current_cmd->command_with_args[0], exec->path,
			exec->shell);
	if (cmd == NULL)
	{
		exit_no_command_found(exec->shell, current_cmd->command_with_args[0]);
	}
	execute_command(exec, cmd, &current_cmd->command_with_args);
	ch_handle_error(exec->shell, NO_MESSAGE);
}

pid_t	child_current_cmd(t_exec *exec, t_exec_list *current_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return (pid);
	child_dup_and_close_pipe(exec);
	if (redirections(*current_cmd) == FALSE)
		ch_handle_error(exec->shell, NO_MESSAGE);
	execute_command_child(exec, current_cmd);
	return (EXIT_FAILURE);
}
