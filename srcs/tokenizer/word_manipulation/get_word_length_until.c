/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_length_until.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:52:14 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 18:10:35 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	get_word_length_until_delimiters(char *line, char *delimiters,
								size_t *str_iter)
{
	int		word_len;
	char	quote_mode;

	quote_mode = '\0';
	word_len = 0;
	while (line[*str_iter])
	{
		if (line[*str_iter] == '\'' || line[*str_iter] == '\"')
			change_quote_mode(line[*str_iter], &quote_mode);
		if (quote_mode == '\0'
			&& ft_strchr(delimiters, line[*str_iter]) != NULL)
			break ;
		else
			++word_len;
		*str_iter += 1;
	}
	return (word_len);
}

int	get_word_length_until_condition(char *line_after_dollar,
								int condition_stop(char, size_t),
								size_t *str_iter)
{
	int		word_len;
	char	quote_mode;
	char	current_char;
	size_t	i;

	quote_mode = '\0';
	word_len = 0;
	i = 0;
	while (line_after_dollar[*str_iter])
	{
		current_char = line_after_dollar[*str_iter];
		if (current_char == '\'' || current_char == '\"')
			change_quote_mode(current_char, &quote_mode);
		if (condition_stop(current_char, i) > 0)
		{
			if (condition_stop(current_char, i) == 2)
				++word_len;
			if (quote_mode == '\0' || are_quotes(current_char))
				break ;
		}
		++word_len;
		*str_iter += 1;
		i += 1;
	}
	return (word_len);
}
