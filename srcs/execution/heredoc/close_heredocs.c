/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:33:18 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 16:10:08 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	close_all_heredocs_except_last(t_exec_list *current_cmd)
{
	int			heredoc_read_fd;
	t_exec_list	*tmp;

	tmp = current_cmd;
	while (tmp)
	{
		heredoc_read_fd = tmp->heredoc_read_fd;
		if (tmp->next != NULL && heredoc_read_fd != PARENT_HEREDOC_FAIL
			&& heredoc_read_fd != PARENT_HEREDOC_NOT_PRESENT)
		{
			close(heredoc_read_fd);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

int	close_current_and_next_heredocs(t_exec_list *current_cmd)
{
	int			heredoc_read_fd;
	t_exec_list	*tmp;

	tmp = current_cmd;
	while (tmp)
	{
		heredoc_read_fd = tmp->heredoc_read_fd;
		close_heredoc_fd_if_present(heredoc_read_fd);
		tmp = tmp->next;
	}
	return (TRUE);
}
