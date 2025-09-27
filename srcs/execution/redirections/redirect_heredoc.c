/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:11:41 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:40:21 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	redirect_heredoc(int fd)
{
	if (fd == PARENT_HEREDOC_FAIL || fd == PARENT_HEREDOC_NOT_PRESENT)
		return (TRUE);
	dup2(fd, STDIN_FILENO);
	return (TRUE);
}
