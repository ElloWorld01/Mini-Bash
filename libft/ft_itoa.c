/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:32:00 by elombard          #+#    #+#             */
/*   Updated: 2022/11/12 10:01:21 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			n = 2147483647;
		else
			n = -n;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	power(int len)
{
	int		n;

	n = 1;
	while (len > 1)
	{
		len--;
		n *= 10;
	}
	return (n);
}

static int	ft_is_minus(int n)
{
	int	result;

	if (n < 0)
		result = 1;
	else
		result = 0;
	return (result);
}

static void	minus_str(int min, char *str)
{
	if (min)
		str[0] = '-';
}

char	*ft_itoa(int nb)
{
	int		intround;
	int		len;
	int		i;
	int		minus;
	char	*str;

	minus = ft_is_minus(nb);
	len = intlen(nb);
	str = malloc(sizeof(char) * (len + minus + 1));
	if (!str)
		return (NULL);
	minus_str(minus, str);
	intround = power(len);
	i = minus;
	while (i < len + minus)
	{
		if (minus)
			str[i++] = -(nb / intround) + '0';
		else
			str[i++] = (nb / intround) + '0';
		nb %= intround;
		intround /= 10;
	}
	str[i] = '\0';
	return (str);
}
