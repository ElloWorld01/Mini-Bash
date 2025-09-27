/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:44:47 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 23:59:40 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	dup_current_pipe(t_exec *exec)
{
	if (exec->pipe_position == 0)
		dup2(exec->pipe_files->dupfds[PIPE_WRITE], STDOUT_FILENO);
	else if (exec->pipe_position == exec->pipes_count)
		dup2(exec->pipe_files->dupfds[PIPE_READ], STDIN_FILENO);
	else
	{
		dup2(exec->pipe_files->dupfds[PIPE_READ], STDIN_FILENO);
		dup2(exec->pipe_files->dupfds[PIPE_WRITE], STDOUT_FILENO);
	}
}

void	close_duped_pipe(t_exec *exec)
{
	if (exec->pipe_position == 0)
		close(exec->pipe_files->dupfds[PIPE_WRITE]);
	else if (exec->pipe_position == exec->pipes_count)
		close(exec->pipe_files->dupfds[PIPE_READ]);
	else
	{
		close(exec->pipe_files->dupfds[PIPE_READ]);
		close(exec->pipe_files->dupfds[PIPE_WRITE]);
	}
}
