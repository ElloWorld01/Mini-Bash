/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:58:38 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:58 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//• %d %id Affiche un nombre décimal (base 10).
int	int_case(int integer)
{
	char	*str;
	int		i;

	str = ft_itoa(integer);
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		write(1, str + i, 1);
		++i;
	}
	free(str);
	return (i);
}
