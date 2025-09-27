/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:15:59 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 16:18:05 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	check_specials(char *line)
{
	if (line != NULL && line[0] == '|')
	{
		print_error_syntax_char('|');
		return (FALSE);
	}
	if (check_consecutive_chars_spaces(line, 1, '|') == FALSE)
		return (FALSE);
	if (check_is_final_pipe_not_followed_by_expression(line) == FALSE)
		return (FALSE);
	if (check_after_redirection_if_filename_is_valid(line) == FALSE)
		return (FALSE);
	if (check_consecutive_chars(line, 2, '>') == FALSE)
		return (FALSE);
	if (check_consecutive_chars(line, 2, '<') == FALSE)
		return (FALSE);
	return (TRUE);
}

int	do_parsing_line(t_shell *shell)
{
	if (is_empty_line(shell->line_readed))
		return (FALSE);
	if (is_quotes_error(shell->line_readed))
		return (FALSE);
	if (check_specials(shell->line_readed) == FALSE)
		return (FALSE);
	return (TRUE);
}
