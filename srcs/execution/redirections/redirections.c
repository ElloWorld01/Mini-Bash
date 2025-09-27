/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:02:46 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:42:24 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	redirections(t_exec_list current_cmd)
{
	t_list_redirections	*current_in_redirections;
	t_list_redirections	*current_out_redirections;

	current_in_redirections = current_cmd.in_redirections;
	current_out_redirections = current_cmd.out_redirections;
	while (current_in_redirections)
	{
		if (redirect_input(current_in_redirections,
				current_cmd.heredoc_read_fd) == FALSE)
			return (FALSE);
		current_in_redirections = current_in_redirections->next;
	}
	close_current_and_next_heredocs(&current_cmd);
	while (current_out_redirections)
	{
		if (redirect_output(current_out_redirections) == FALSE)
			return (FALSE);
		current_out_redirections = current_out_redirections->next;
	}
	return (TRUE);
}
