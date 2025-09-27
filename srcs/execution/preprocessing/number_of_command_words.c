/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_command_words.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:54 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:37:19 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	number_of_command_words(t_token_list *current)
{
	int	count;

	count = 0;
	while (current && current->type != TOKEN_PIPE)
	{
		if (current->type == TOKEN_WORD)
			count++;
		current = current->next;
	}
	return (count);
}
