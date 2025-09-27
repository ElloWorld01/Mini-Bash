/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_final_pipe_not_followed_by_expre          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:02:44 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 16:33:25 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	check_is_final_pipe_not_followed_by_expression(char *line)
{
	int	index_last_pipe;

	index_last_pipe = ft_strlen(line) - 1;
	while (index_last_pipe >= 0
		&& ft_strchr(SHELL_SPACES, line[index_last_pipe]) != NULL)
		--index_last_pipe;
	if (index_last_pipe >= 0 && line[index_last_pipe] == '|')
	{
		print_error_syntax_char('|');
		return (FALSE);
	}
	return (TRUE);
}
