/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:20:49 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:59:27 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	wait_childs(t_exec exec, int *stat)
{
	int	i;

	i = 0;
	while (i < *exec.commands_count)
	{
		if (exec.childs_pids[i] != -1)
			waitpid(exec.childs_pids[i], stat, 0);
		++i;
	}
}
