/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:49:35 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 16:51:36 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	case_0_before(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < ft_strlen(str) - LONG_LONG_LEN)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_long_long_max_min(char *str)
{
	if (ft_strlen(str) < LONG_LONG_LEN)
		return (1);
	if (ft_strlen(str) == LONG_LONG_LEN)
	{
		if (ft_strncmp(str, LONG_LONG_MAX_STR, LONG_LONG_LEN) > 0)
			return (0);
	}
	else if (ft_strlen(str) == LONG_LONG_LEN_MINUS)
	{
		if (ft_strncmp(str, LONG_LONG_MIN_STR_MINUS, LONG_LONG_LEN_MINUS) > 0)
			return (0);
	}
	else if (ft_strlen(str) > LONG_LONG_LEN_MINUS)
	{
		if (str[0] == '-')
		{
			if (ft_strncmp(str + ft_strlen(str)
					- LONG_LONG_LEN, LONG_LONG_MIN_STR, LONG_LONG_LEN) > 0)
				return (0);
		}
		else if (ft_strncmp(str + ft_strlen(str)
				- LONG_LONG_LEN, LONG_LONG_MAX_STR, LONG_LONG_LEN) > 0)
			return (0);
	}
	return (case_0_before(str));
}

static int	is_number(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (1);
	if ((str[0] == '-' || str[0] == '+') && ft_strlen(str) == 1)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_long_long_max_min(str));
}

int	check_long_long(char *str_to_check)
{
	if (str_to_check == NULL)
		return (0);
	if (ft_strlen(str_to_check) == 1)
	{
		if (!is_number(str_to_check) && str_to_check[0] != '0')
			return (0);
	}
	else if (ft_strlen(str_to_check) > 1)
	{
		if (is_number(str_to_check) == 0)
			return (0);
	}
	return (1);
}
