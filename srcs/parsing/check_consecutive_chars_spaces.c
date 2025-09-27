/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_consecutive_chars_spaces.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:01:39 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 16:44:45 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	modify_count(const char *line, int *count, char current_char)
{
	if (*line == current_char)
		*count += 1;
	else if (ft_strchr(SHELL_SPACES, *line) == NULL)
		*count = 0;
}

int	check_consecutive_chars_spaces(const char *line, int limit, char c)
{
	int		count;
	char	quote_mode;

	quote_mode = '\0';
	count = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			change_quote_mode(*line, &quote_mode);
			count = 0;
		}
		if (quote_mode == '\0')
		{
			modify_count(line, &count, c);
			if (count > limit)
			{
				print_error_syntax_char(c);
				return (FALSE);
			}
		}
		++line;
	}
	return (TRUE);
}
