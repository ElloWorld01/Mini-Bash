/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_amount_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:15:48 by elombard          #+#    #+#             */
/*   Updated: 2023/10/10 02:15:48 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	check_amount_char(char *str, char *to_find)
{
	int	iter;
	int	count;

	count = 0;
	iter = 0;
	while (str[iter])
	{
		if (ft_strchr(to_find, str[iter]))
			count += 1;
		++iter;
	}
	return (count);
}
