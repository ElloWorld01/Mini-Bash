/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_childs_pids_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:21:20 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:59:23 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	initialize_child_process_pids_with_default(t_exec *exec)
{
	ft_memset(exec->childs_pids, -1, *exec->commands_count * sizeof(pid_t));
}

void	alloc_childs_pids_array(t_exec *exec)
{
	if (*exec->commands_count == 0)
	{
		exec->childs_pids = NULL;
		return ;
	}
	exec->childs_pids = ms_calloc(
			*exec->commands_count, sizeof(pid_t), exec->shell);
	initialize_child_process_pids_with_default(exec);
}
