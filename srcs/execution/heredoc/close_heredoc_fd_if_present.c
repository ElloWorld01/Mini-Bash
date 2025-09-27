/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_heredoc_fd_if_present.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:08:16 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 16:10:58 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	close_heredoc_fd_if_present(int fd_heredoc)
{
	if (fd_heredoc != PARENT_HEREDOC_NOT_PRESENT
		&& fd_heredoc != PARENT_HEREDOC_FAIL)
		close(fd_heredoc);
}
