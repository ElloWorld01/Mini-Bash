/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_only_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:22:28 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:18:54 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	do_builtin_in_child(t_exec *exec, t_exec_list *current_cmd)
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid == -1)
	{
		printerr_shell_ln("fork() failed, stopping execution");
		return ;
	}
	if (pid == 0)
	{
		if (redirections(*current_cmd) == FALSE)
			ch_handle_error(exec->shell, NO_MESSAGE);
		exit_status = execute_child_builtins(exec->shell,
				current_cmd->command_with_args);
		if (exit_status != -1)
			ch_exit(exec->shell, exit_status);
		ch_exit(exec->shell, CMD_FAILURE);
	}
	else
	{
		waitpid(pid, &exec->shell->exit_status, 0);
		exec->shell->exit_status
			= get_correct_return_code(exec->shell->exit_status);
	}
}

static void	do_only_builtin(t_exec *exec, t_exec_list *current_cmd)
{
	int	exec_status;

	if (current_cmd->command_with_args == NULL
		|| current_cmd->command_with_args[0] == NULL)
		return ;
	exec_status = execute_parent_builtins(exec->shell,
			current_cmd->command_with_args);
	if (exec_status != -1)
	{
		exec->shell->exit_status = exec_status;
		return ;
	}
	do_builtin_in_child(exec, current_cmd);
}

int	check_only_builtin(t_exec *exec)
{
	t_exec_list	*current_cmd;

	current_cmd = exec->exec_list;
	if (current_cmd == NULL)
		return (FALSE);
	if (current_cmd->command_with_args == NULL)
		return (FALSE);
	if (current_cmd->command_with_args[0] == NULL)
		return (FALSE);
	if (current_cmd->next != NULL)
		return (FALSE);
	if (can_use_builtin(current_cmd->command_with_args[0]) == TRUE)
	{
		do_only_builtin(exec, current_cmd);
		return (TRUE);
	}
	return (FALSE);
}
