/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:07:42 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:55:03 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_utoa(unsigned int arg);
static int	power(int len);
static int	intlen(unsigned int n);

// • %u Affiche un nombre non signé décimal (base 10).
int	unsigned_int_case(unsigned int arg)
{
	char	*str;
	int		i;

	str = ft_utoa(arg);
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		++i;
	}
	free(str);
	return (i);
}

static int	intlen(unsigned int n)
{
	int	len;

	len = 0;
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
	int	n;

	n = 1;
	while (len > 1)
	{
		len--;
		n *= 10;
	}
	return (n);
}

static char	*ft_utoa(unsigned int arg)
{
	int		intround;
	int		len;
	int		i;
	char	*str;

	len = intlen(arg);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	intround = power(len);
	i = 0;
	while (i < len)
	{
		str[i++] = (arg / intround) + '0';
		arg %= intround;
		intround /= 10;
	}
	str[i] = '\0';
	return (str);
}
