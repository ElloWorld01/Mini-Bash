/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadeci_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:49:54 by elombard          #+#    #+#             */
/*   Updated: 2023/02/27 22:31:19 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO si cela ne fonctionne pas, mettre un \0 à la fin de la string peut être ?
void	hexarray(char *ptr_str, uintptr_t arg);
int		hexa_size(uintptr_t arg);

void	hexarray(char *ptr_str, uintptr_t arg)
{
	char	c;
	int		tmp;
	int		i;

	i = hexa_size(arg) - 1;
	while (arg > 0)
	{
		tmp = arg % 16;
		if (arg % 16 <= 9)
		{
			c = ((char)tmp + '0');
			ptr_str[i] = c;
		}
		else
		{
			c = (((char)tmp - 10) + 'a');
			ptr_str[i] = c;
		}
		arg /= 16;
		--i;
	}
}

int	hexa_size(uintptr_t arg)
{
	int	size;

	size = 0;
	while (arg > 0)
	{
		arg /= 16;
		++size;
	}
	return (size);
}
