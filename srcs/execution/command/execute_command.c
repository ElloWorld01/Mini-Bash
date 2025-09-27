/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:18:38 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:06 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	execute_command_with_arguments(t_exec *exec, char *cmd,
			char ***args)
{
	if (execve(cmd, (*args), exec->env) == -1)
	{
		try_execute_file(cmd, exec->shell);
		printerr(cmd);
		ms_free(cmd);
		cmd = NULL;
		free_array_of_char_array(*args);
		*args = NULL;
		free(exec->childs_pids);
		exec->childs_pids = NULL;
		ch_handle_error(exec->shell, CODE_127_NO_PRESENT);
	}
}

void	execute_command(t_exec *exec, char *cmd, char ***args)
{
	if (!(*args))
	{
		printerr(cmd);
		ms_free(cmd);
		cmd = NULL;
		free(exec->childs_pids);
		exec->childs_pids = NULL;
		ch_handle_error(exec->shell, CODE_127_NO_PRESENT);
	}
	execute_command_with_arguments(exec, cmd, args);
}
