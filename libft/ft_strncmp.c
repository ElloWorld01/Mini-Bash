/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:28 by elombard          #+#    #+#             */
/*   Updated: 2022/11/25 19:01:05 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*s1bis;
	unsigned char		*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	i = 0;
	while (i < n && (s1bis[i] != '\0' || s2bis[i] != '\0'))
	{
		if (s1bis[i] != s2bis[i])
			return (s1bis[i] - s2bis[i]);
		i++;
	}
	return (0);
}
