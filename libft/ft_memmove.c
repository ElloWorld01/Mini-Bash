/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:00:34 by elombard          #+#    #+#             */
/*   Updated: 2022/11/25 18:59:15 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_str;
	char	*d_str;
	size_t	i;

	s_str = (char *)src;
	d_str = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d_str > s_str)
		while (len--)
			d_str[len] = s_str[len];
	else
	{
		while (i < len)
		{
			d_str[i] = s_str[i];
			i++;
		}
	}
	return (dst);
}
