/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombardo <elombardo@student.42nice.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:19:29 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 22:10:15 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	prepare_exec(t_shell *shell, t_exec **exec, int *stat,
					t_exec_list **current_cmd)
{
	(*stat) = -1;
	(*exec) = shell->exec;
	alloc_childs_pids_array((*exec));
	(*exec)->path = get_path_line_in_env((*exec)->env);
	(*current_cmd) = (*exec)->exec_list;
	if (*current_cmd == NULL)
		return (FALSE);
	(*exec)->pipes_count = *(*exec)->commands_count - 1;
	return (TRUE);
}

int	execute_current_cmd(t_exec *exec, int i, t_exec_list *current_cmd)
{
	exec->pipe_position = i;
	parent_handle_current_pipe(exec);
	exec->childs_pids[i] = child_current_cmd(exec, current_cmd);
	close_heredoc_fd_if_present(current_cmd->heredoc_read_fd);
	parent_close_current_unused_pipe_files(exec);
	if (exec->childs_pids[i] == -1)
	{
		printerr_shell_ln("fork() failed, stopping execution");
		return (FALSE);
	}
	return (TRUE);
}

int	execution(t_shell *shell)
{
	t_exec		*exec;
	int			stat;
	int			i;
	t_exec_list	*current_cmd;

	i = 0;
	if (prepare_exec(shell, &exec, &stat, &current_cmd) == FALSE)
		return (SUCCESS);
	parent_init_pipe_files(exec);
	while (current_cmd)
	{
		if (execute_current_cmd(exec, i, current_cmd) == FALSE)
			break ;
		current_cmd = current_cmd->next;
		i += 1;
	}
	wait_childs(*exec, &stat);
	return (get_correct_return_code(stat));
}

void	do_execution(t_shell *shell)
{
	if (shell->tokenizer->head == NULL)
		return ;
	token_list_to_exec(shell);
	heredoc_stop_signal_reset();
	signal(SIGINT, SIG_IGN);
	if (do_heredocs(shell->exec) == FALSE)
		return ;
	signal(SIGQUIT, sigquit_newline);
	signal(SIGINT, sigint_newline);
	if (check_only_builtin(shell->exec))
		return ;
	shell->exit_status = execution(shell);
}
