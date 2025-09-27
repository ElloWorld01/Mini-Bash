/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:16:17 by elombard          #+#    #+#             */
/*   Updated: 2022/11/26 10:56:03 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	i;
	int	result;

	minus = 1;
	i = 0;
	while (space(str[i]))
		i++;
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			minus = -1;
		++i;
	}
	if (!str[i] || (!ft_isdigit(str[i])))
		return (0);
	if ((str[i + 1] && !ft_isdigit(str[i + 1])))
		return ((str[i] - '0') * minus);
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * minus);
}
