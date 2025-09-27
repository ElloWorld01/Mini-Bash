/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:53:24 by elombard          #+#    #+#             */
/*   Updated: 2023/09/26 12:46:16 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*search_line(int fd, char *stash);
char	*get_current_line(char *stash);
char	*clean_stash(char *stash);
size_t	my_strlen(const char *s);
void	*my_calloc(size_t count, size_t size);
char	*my_strjoin(char *stash, char *buff);
char	*my_strchr(char *s, int c);

#endif