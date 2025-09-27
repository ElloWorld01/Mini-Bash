/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:01:26 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:55:01 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// • %p L’argument de pointeur void * doit être affiché en hexadécimal.
int	pointer_case(uintptr_t arg)
{
	int		i;
	int		size;
	char	*ptr_str;

	if (arg == 0)
		return (ft_printf("%s", NULL));
	ptr_str = malloc(sizeof(char) * (hexa_size(arg)));
	if (!ptr_str)
	{
		ft_printf("%s", NULL);
		return (0);
	}
	i = write(1, "0x", 2);
	hexarray(ptr_str, arg);
	size = hexa_size(arg);
	i += write(1, ptr_str, size);
	free(ptr_str);
	return (i);
}
