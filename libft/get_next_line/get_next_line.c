/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:23:18 by elombard          #+#    #+#             */
/*   Updated: 2023/09/26 12:47:19 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*notnull;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free(stash);
		return (stash = NULL);
	}
	notnull = search_line(fd, stash);
	if (!notnull)
		return (free(stash), stash = NULL);
	stash = notnull;
	line = get_current_line(stash);
	if (!line)
		return (free(stash), stash = NULL);
	stash = clean_stash(stash);
	return (line);
}

char	*search_line(int fd, char *stash)
{
	char	*buf;
	char	*notnull;
	int		i;

	buf = malloc((BUFFER_SIZE + (i = 1)) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!my_strchr(stash, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free(buf), buf = NULL);
		buf[i] = '\0';
		if (!stash)
			stash = my_calloc(sizeof(char), 1);
		if (!stash)
			return (free(notnull), stash = NULL);
		notnull = my_strjoin(stash, buf);
		if (!notnull)
			return (free(stash), free(notnull), stash = NULL);
		stash = notnull;
	}
	return (free(buf), stash);
}

char	*get_current_line(char *stash)
{
	int		i;
	char	*new;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		++i;
	new = my_calloc(i + 2, sizeof(char));
	if (!new)
		return (free(stash), stash = NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		++i;
	}
	if (stash[i] == '\n')
	{
		new[i] = stash[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL);
	new = my_calloc(my_strlen(stash) - i + 1, sizeof(char));
	if (!new)
		return (free(stash), stash = NULL);
	j = 0;
	while (stash[i++])
		new[j++] = stash[i];
	new[j] = 0;
	return (free(stash), new);
}
