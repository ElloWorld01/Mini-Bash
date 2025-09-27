/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:01:26 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:54 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	to_lower(char *ptr_str);
static void	to_upper(char *ptr_str);

// • %x Affiche un nombre en hexadécimal avec des lettres minuscules.
int	hexa_lower_case(unsigned int arg)
{
	int		i;
	int		size;
	char	*ptr_str;

	if (!arg)
		return (write(1, "0", 1));
	ptr_str = malloc(sizeof(char) * (hexa_size(arg)));
	if (!ptr_str)
		return (0);
	hexarray(ptr_str, arg);
	size = hexa_size(arg);
	to_lower(ptr_str);
	i = write(1, ptr_str, size);
	free(ptr_str);
	return (i);
}

// • %X Affiche un nombre en hexadécimal avec des lettres majuscules.
int	hexa_upper_case(unsigned int arg)
{
	int		i;
	int		size;
	char	*ptr_str;

	if (!arg)
		return (write(1, "0", 1));
	ptr_str = malloc(sizeof(char) * (hexa_size(arg)));
	if (!ptr_str)
		return (0);
	hexarray(ptr_str, arg);
	size = hexa_size(arg);
	to_upper(ptr_str);
	i = write(1, ptr_str, size);
	free(ptr_str);
	return (i);
}

static void	to_upper(char *ptr_str)
{
	int	i;

	i = 0;
	while (ptr_str[i])
	{
		ptr_str[i] = ft_toupper(ptr_str[i]);
		++i;
	}
}

static void	to_lower(char *ptr_str)
{
	int	i;

	i = 0;
	while (ptr_str[i])
	{
		ptr_str[i] = ft_tolower(ptr_str[i]);
		++i;
	}
}
