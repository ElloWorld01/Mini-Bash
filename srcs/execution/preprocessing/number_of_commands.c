/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:43:41 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:37:29 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	number_of_commands(t_token_list *head)
{
	int				count;
	t_token_list	*tmp;

	count = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->type == TOKEN_PIPE)
			++count;
		tmp = tmp->next;
	}
	return (count + 1);
}
