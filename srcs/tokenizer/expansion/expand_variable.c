/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:50:22 by elombard          #+#    #+#             */
/*   Updated: 2023/11/30 19:36:39 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static char *
	expand_variable(char *word_with_quotes, int *str_iter, t_shell *shell)
{
	char	*p_old_word_with_quotes;

	p_old_word_with_quotes = word_with_quotes;
	word_with_quotes = expansion(p_old_word_with_quotes, str_iter, shell);
	ms_free(p_old_word_with_quotes);
	p_old_word_with_quotes = NULL;
	return (word_with_quotes);
}

static int	string_ends_with_dollar(char current_char, char next_char)
{
	return (current_char == '$' && next_char == '\0');
}

static int	can_expand_var(char current_char, char quote_mode, char next_char)
{
	return (current_char == '$' && quote_mode != '\''
		&& is_env_name_char_allowed(next_char));
}

char	*expand_variables_if_any(char *string, t_shell *shell)
{
	int		str_iter;
	char	quote_mode;
	char	current_char;
	char	next_char;

	str_iter = 0;
	quote_mode = '\0';
	if (check_amount_char(string, "$") == 0)
		return (string);
	while (string != NULL && string[str_iter])
	{
		current_char = string[str_iter];
		next_char = string[str_iter + 1];
		if (string_ends_with_dollar(current_char, next_char))
			return (string);
		if (can_expand_var(current_char, quote_mode, next_char))
			string = expand_variable(string, &str_iter, shell);
		if (current_char == '$' && next_char == '?' && quote_mode != '\'')
			string = expand_exit_status(string, &str_iter, shell);
		quote_mode = handle_quote_pair(quote_mode, current_char);
		++str_iter;
	}
	return (string);
}
