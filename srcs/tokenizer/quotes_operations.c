/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:21:04 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:52:26 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	get_count_quotes_in_pairs(const char *line)
{
	int		count;
	char	quote;
	int		str_iter;

	quote = '\0';
	str_iter = 0;
	count = 0;
	while (line[str_iter])
	{
		if (line[str_iter] == '\'' || line[str_iter] == '\"')
		{
			if (quote == '\0')
			{
				quote = line[str_iter];
				count += 1;
			}
			else if (line[str_iter] == quote)
			{
				quote = '\0';
				count += 1;
			}
		}
		str_iter += 1;
	}
	return (count);
}

char	*check_quotes_and_append_char(char *word, char *token)
{
	char	quote;
	int		word_iter;
	int		token_iter;

	quote = '\0';
	word_iter = 0;
	token_iter = 0;
	if (word == NULL || token == NULL)
		return (NULL);
	while (word[word_iter])
	{
		if (!((word[word_iter] == '\'' || word[word_iter] == '\"')
				&& change_quote_pair(&quote, word, word_iter)))
		{
			token[token_iter] = word[word_iter];
			token_iter += 1;
		}
		word_iter += 1;
	}
	token[token_iter] = '\0';
	return (token);
}

char	*remove_quotes_from_word(char *word, t_shell *shell)
{
	char	*token;

	token = malloc_token_without_quotes(word, shell);
	token = check_quotes_and_append_char(word, token);
	return (token);
}

int	change_quote_pair(char *quote, const char *word, int word_iter)
{
	if (*quote == '\0')
		*quote = word[word_iter];
	else if (word[word_iter] == *quote)
		*quote = '\0';
	else
		return (0);
	return (1);
}

char	handle_quote_pair(char quote, char c)
{
	if (c == '\'' || c == '\"')
	{
		if (quote == '\0')
			quote = c;
		else if (c == quote)
			quote = '\0';
	}
	return (quote);
}
