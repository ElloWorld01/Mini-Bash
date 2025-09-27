/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:56 by elombard          #+#    #+#             */
/*   Updated: 2023/11/21 23:22:54 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	free_current_redirection(t_list_redirections **redirections)
{
	t_list_redirections	*tmp_to_free;

	while (*redirections)
	{
		ms_free((*redirections)->filename);
		(*redirections)->filename = NULL;
		tmp_to_free = *redirections;
		*redirections = (*redirections)->next;
		ms_free(tmp_to_free);
		tmp_to_free = NULL;
	}
	redirections = NULL;
}

void	free_current_command(t_exec_list *exec_list)
{
	int	i;

	i = 0;
	if (exec_list == NULL || exec_list->command_with_args == NULL)
		return ;
	while (exec_list->command_with_args[i] != NULL)
	{
		ms_free(exec_list->command_with_args[i]);
		exec_list->command_with_args[i] = NULL;
		++i;
	}
	ms_free(exec_list->command_with_args);
	exec_list->command_with_args = NULL;
}

void	init_exec(t_shell *shell)
{
	t_exec	*exec;

	exec = ms_calloc(1, sizeof(t_exec), shell);
	exec->shell = shell;
	exec->env = shell->env;
	exec->pipe_files = NULL;
	exec->exec_list = NULL;
	exec->childs_pids = NULL;
	exec->commands_count = NULL;
	shell->exec = exec;
}

void	free_exec(t_shell *shell)
{
	t_exec_list	*exec_list;
	t_exec_list	*tmp_to_free;

	exec_list = shell->exec->exec_list;
	if (exec_list != NULL)
	{
		while (exec_list)
		{
			free_current_command(exec_list);
			free_current_redirection(&exec_list->in_redirections);
			free_current_redirection(&exec_list->out_redirections);
			tmp_to_free = exec_list;
			exec_list = exec_list->next;
			ms_free(tmp_to_free);
			tmp_to_free = NULL;
		}
	}
	ms_free(shell->exec->commands_count);
	shell->exec->commands_count = NULL;
	ms_free(shell->exec->childs_pids);
	shell->exec->childs_pids = NULL;
	ms_free(shell->exec->pipe_files);
	shell->exec->pipe_files = NULL;
	ms_free(shell->exec);
	shell->exec = NULL;
}
