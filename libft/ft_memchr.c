/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:00:23 by elombard          #+#    #+#             */
/*   Updated: 2022/11/07 08:55:59 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;
	int				found;

	p = (unsigned char *)s;
	i = 0;
	found = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (found == 1)
		return (p + i);
	else
		return (NULL);
}
