/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:50:41 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 16:33:45 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	is_empty_line(char *str)
{
	int		iter;
	size_t	count;
	size_t	line_len;

	iter = 0;
	count = 0;
	line_len = ft_strlen(str);
	if (str == NULL)
		return (TRUE);
	while (str[iter])
	{
		if (str[iter] < 33)
			++count;
		++iter;
	}
	return (count == line_len);
}
