/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:51:32 by elombard          #+#    #+#             */
/*   Updated: 2022/11/25 19:15:23 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		temp;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	temp = i;
	if (dstsize < i)
		return (dstsize + ft_strlen(src));
	ft_strlcpy(dst + i, src, dstsize - i);
	return (temp + ft_strlen(src));
}
