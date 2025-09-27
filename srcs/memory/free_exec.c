/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:46:30 by elombard          #+#    #+#             */
/*   Updated: 2023/11/23 12:57:45 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

void	free_array_of_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		ms_free(array[i]);
		array[i] = NULL;
		i++;
	}
	ms_free(array);
	array = NULL;
}

void	free_close(char *cmd, char **args)
{
	free_array_of_char_array(args);
	args = NULL;
	ms_free(cmd);
	cmd = NULL;
}
