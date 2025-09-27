/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_pipes_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:05:53 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 23:52:53 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	parent_init_pipe_files(t_exec *exec)
{
	if (*exec->commands_count <= 1)
		return ;
	if (exec->pipe_files == NULL)
		exec->pipe_files = ms_calloc(1, sizeof(t_pipe_files), exec->shell);
	exec->pipe_files->pipefds[PIPE_READ] = -1;
	exec->pipe_files->pipefds[PIPE_WRITE] = -1;
	exec->pipe_files->dupfds[PIPE_READ] = -1;
	exec->pipe_files->dupfds[PIPE_WRITE] = -1;
	exec->pipe_files->savefd = -1;
}

void	parent_handle_current_pipe(t_exec *exec)
{
	if (*exec->commands_count <= 1)
		return ;
	if (exec->pipe_position == 0)
	{
		pipe(exec->pipe_files->pipefds);
		exec->pipe_files->savefd = exec->pipe_files->pipefds[PIPE_READ];
		exec->pipe_files->dupfds[PIPE_WRITE]
			= exec->pipe_files->pipefds[PIPE_WRITE];
	}
	else if (exec->pipe_position == exec->pipes_count)
	{
		exec->pipe_files->dupfds[PIPE_READ] = exec->pipe_files->savefd;
	}
	else
	{
		pipe(exec->pipe_files->pipefds);
		exec->pipe_files->dupfds[PIPE_READ] = exec->pipe_files->savefd;
		exec->pipe_files->dupfds[PIPE_WRITE]
			= exec->pipe_files->pipefds[PIPE_WRITE];
		exec->pipe_files->savefd = exec->pipe_files->pipefds[PIPE_READ];
	}
}

static void	parent_close_current_pipe(t_exec *exec)
{
	close_duped_pipe(exec);
}

void	parent_close_current_unused_pipe_files(t_exec *exec)
{
	if (*exec->commands_count <= 1)
		return ;
	parent_close_current_pipe(exec);
}
