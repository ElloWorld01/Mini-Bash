/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_handle_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:49:24 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 23:57:53 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	child_close_current_pipe(t_exec *exec)
{
	close_duped_pipe(exec);
	if (exec->pipe_position != exec->pipes_count)
		close(exec->pipe_files->savefd);
}

void	child_dup_and_close_pipe(t_exec *exec)
{
	if (*exec->commands_count <= 1)
		return ;
	dup_current_pipe(exec);
	child_close_current_pipe(exec);
}
