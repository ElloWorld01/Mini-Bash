/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:34:03 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 20:21:51 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	open_outfile(char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0000644);
	if (fd == -1)
	{
		printerr_outfile(filename);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

int	open_outfile_append(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0000644);
	if (fd == -1)
	{
		printerr_outfile(filename);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

int	redirect_output(t_list_redirections *current_redirection)
{
	t_token_type	redirect_type;
	char			*filename;

	redirect_type = current_redirection->type;
	filename = current_redirection->filename;
	if (redirect_type == TOKEN_OUTFILE_APPEND)
	{
		return (open_outfile_append(filename));
	}
	else if (redirect_type == TOKEN_OUTFILE_NORMAL)
	{
		return (open_outfile(filename));
	}
	return (FALSE);
}
