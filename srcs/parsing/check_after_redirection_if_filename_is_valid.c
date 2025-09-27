/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_after_redirection_if_filename_is_va          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:01:29 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 16:43:53 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static int	valid_after_redirection(char *line, int *iter)
{
	if (line[(*iter)] == '>' || line[(*iter)] == '<')
	{
		(*iter) += 1;
		if (line[(*iter)] == '>' || line[(*iter)] == '<')
			(*iter) += 1;
		if (ft_strchr("\n\v\f\r\0", line[(*iter)]) != NULL)
		{
			printerr_syntax_str("newline");
			return (FALSE);
		}
		if (ft_strchr(SHELL_SPACES, line[(*iter)]) != NULL)
			(*iter) += 1;
		if (ft_strchr("|><", line[(*iter)]) != NULL)
		{
			print_error_syntax_char(line[(*iter)]);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	check_after_redirection_if_filename_is_valid(char *line)
{
	int		iter;
	char	quote_mode;

	iter = 0;
	quote_mode = '\0';
	while (line[iter])
	{
		if (line[iter] == '\'' || line[iter] == '\"')
			change_quote_mode(line[iter], &quote_mode);
		if (quote_mode == '\0')
		{
			if (valid_after_redirection(line, &iter) == FALSE)
				return (FALSE);
		}
		++iter;
	}
	return (TRUE);
}
