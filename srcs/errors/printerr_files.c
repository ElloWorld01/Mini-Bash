/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:46:07 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 15:34:40 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	printerr_heredoc_eof(char *stop_word)
{
	printerr("\n");
	printerr_shell(HEREDOC_ERR);
	printerr(stop_word);
	printerr("')\n");
}

char	*printerr_infile(char *filename)
{
	if (access(filename, F_OK) == -1)
		printerr_src_msg_ln(filename, MSG_NO_SUCH_FILE_OR_DIR);
	else if (is_directory(filename) == TRUE)
		printerr_src_msg_ln(filename, MSG_IS_A_DIR);
	else if (access(filename, R_OK) == -1)
		printerr_src_msg_ln(filename, MSG_PERM_DENIED);
	else
		printerr_src_msg_ln(filename, MSG_NO_SUCH_FILE_OR_DIR);
	return (NULL);
}

char	*printerr_outfile(char *filename)
{
	if (is_directory(filename) == TRUE)
		printerr_src_msg_ln(filename, MSG_IS_A_DIR);
	else if (access(filename, W_OK) == -1)
		printerr_src_msg_ln(filename, MSG_PERM_DENIED);
	else
		printerr_src_msg_ln(filename, MSG_PERM_DENIED);
	return (NULL);
}
