/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:44:27 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:17:14 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

static void	print_error_eof(char quote_mode)
{
	printerr_shell(NAME_LOWER": unexpected EOF while looking for matching `");
	ft_putchar_fd(quote_mode, STDERR_FILENO);
	printerr("'\n");
}

void	check_quote_pairs(const char *str, char *quote_mode, int *quote_count)
{
	int	str_iter;

	str_iter = 0;
	while (str[str_iter])
	{
		if (str[str_iter] == '\'' || str[str_iter] == '\"')
		{
			if ((*quote_mode) == '\0' || (*quote_mode) == str[str_iter])
				++(*quote_count);
			(*quote_mode) = handle_quote_pair((*quote_mode), str[str_iter]);
		}
		++str_iter;
	}
}

int	is_quotes_error(char *str)
{
	char	quote_mode;
	int		quote_count;

	quote_count = 0;
	quote_mode = '\0';
	if (check_amount_char(str, "\'") == 0 && check_amount_char(str, "\"") == 0)
		return (FALSE);
	check_quote_pairs(str, &quote_mode, &quote_count);
	if (quote_count % 2 != 0)
	{
		print_error_eof(quote_mode);
		return (TRUE);
	}
	return (FALSE);
}
