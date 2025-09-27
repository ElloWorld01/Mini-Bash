/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:35:14 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 21:43:13 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	has_dot_slash(const char *filename)
{
	if (filename == NULL || filename[0] == '\0' || filename[1] == '\0')
		return (FALSE);
	return (filename[0] == '.' && filename[1] == '/');
}

int	is_directory(char *filename)
{
	struct stat	file_stat;

	if (stat(filename, &file_stat) == -1)
		return (FALSE);
	return ((file_stat.st_mode & 0170000) == (0040000));
}
