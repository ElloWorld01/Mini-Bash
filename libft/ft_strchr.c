/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:00:42 by elombard          #+#    #+#             */
/*   Updated: 2022/11/26 10:00:02 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	t;

	t = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == t)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && t == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
