/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:59:44 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:45 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// • %c Affiche un seul caractère.
int	char_case(int integer)
{
	char	c;

	c = integer;
	write(1, &c, 1);
	return (1);
}

// % 
int	only_percent_case(const char *format)
{
	write(1, "%", 1);
	write(1, format, 1);
	return (1);
}

// • %% Affiche un signe pourcentage.
int	percent_percent_case(void)
{
	write(1, "%", 1);
	return (1);
}

// • char* %s
int	string_case(char *arg)
{
	int	i;

	if (arg == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (arg[i])
	{
		write(1, arg + i, 1);
		i++;
	}
	return (i);
}
