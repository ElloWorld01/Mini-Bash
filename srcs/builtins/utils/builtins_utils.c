/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:41:00 by elombard          #+#    #+#             */
/*   Updated: 2023/11/25 15:41:21 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

int	args_counter(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}
