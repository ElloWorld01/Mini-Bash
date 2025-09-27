/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:34:03 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 20:20:39 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printerr_infile(filename);
		return (FALSE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (TRUE);
}

int	redirect_input(t_list_redirections *current_redirection, int heredoc_fd)
{
	t_token_type	redirect_type;
	char			*filename;

	redirect_type = current_redirection->type;
	filename = current_redirection->filename;
	if (redirect_type == TOKEN_HEREDOC_WORD)
	{
		return (redirect_heredoc(heredoc_fd));
	}
	else if (redirect_type == TOKEN_INFILE)
	{
		return (open_infile(filename));
	}
	return (FALSE);
}
