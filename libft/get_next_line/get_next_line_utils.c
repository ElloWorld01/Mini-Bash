/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:53:22 by elombard          #+#    #+#             */
/*   Updated: 2023/09/26 12:47:05 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*my_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			n;

	if (count && (((long)count * (long)size) / count != size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	n = count * size;
	p = ptr;
	while (n--)
		*p++ = 0;
	return (ptr);
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = my_calloc((my_strlen(s1) + my_strlen(s2)) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*my_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	if (!s[i] && !c)
		return ((char *) &s[i]);
	return (NULL);
}
