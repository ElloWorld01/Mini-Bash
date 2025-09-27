/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:56:48 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:58:04 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	process_current_heredoc(t_exec *exec,
					t_list_redirections *current_redirection,
					int file_descriptor)
{
	char	*stop_word;

	stop_word = current_redirection->filename;
	if (file_descriptor != PARENT_HEREDOC_NOT_PRESENT)
		close(file_descriptor);
	file_descriptor = do_current_heredoc(stop_word, exec->shell);
	return (file_descriptor);
}

int	do_heredocs(t_exec *exec)
{
	t_list_redirections	*current_redirection;
	t_exec_list			*current_exec_list;
	int					file_descriptor;

	current_exec_list = exec->exec_list;
	while (current_exec_list != NULL)
	{
		file_descriptor = PARENT_HEREDOC_NOT_PRESENT;
		current_redirection = current_exec_list->in_redirections;
		while (current_redirection)
		{
			if (current_redirection->type == TOKEN_HEREDOC_WORD)
			{
				file_descriptor = process_current_heredoc(exec,
						current_redirection, file_descriptor);
				if (file_descriptor == PARENT_HEREDOC_FAIL
					|| file_descriptor == PARENT_HEREDOC_INTERRUPT)
					return (FALSE);
			}
			current_redirection = current_redirection->next;
		}
		current_exec_list->heredoc_read_fd = file_descriptor;
		current_exec_list = current_exec_list->next;
	}
	return (TRUE);
}
