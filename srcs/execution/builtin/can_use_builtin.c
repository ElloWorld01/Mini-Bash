/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_use_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:32:02 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:57:05 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	can_use_builtin(char *cmd)
{
	return (compare_exactly(cmd, "cd") || compare_exactly(cmd, "echo")
		|| compare_exactly(cmd, "env") || compare_exactly(cmd, "exit")
		|| compare_exactly(cmd, "export") || compare_exactly(cmd, "pwd")
		|| compare_exactly(cmd, "unset"));
}
