/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:49:24 by elombard          #+#    #+#             */
/*   Updated: 2023/11/30 20:21:27 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static char	*alter_word_status(int *str_iter, t_shell *shell)
{
	char	*word_expanded;

	shell->tokenizer->alter_word->new_word = ft_itoa(shell->exit_status);
	word_expanded = replace_or_remove_word_if_no_substitute(
			shell->tokenizer->alter_word, shell, str_iter);
	adjust_str_iter_if_end_of_string(str_iter, word_expanded);
	return (word_expanded);
}

static
char	*expansion_status(char *word_to_expand, int *str_iter, t_shell *shell)
{
	char	*dollar_word;
	char	*word_expanded;
	int		init_iter;

	init_iter = *str_iter;
	dollar_word = ft_strdup("?");
	init_alter_word(shell, word_to_expand, dollar_word, init_iter);
	word_expanded = alter_word_status(str_iter, shell);
	free_alter_word(shell);
	return (word_expanded);
}

char *
	expand_exit_status(char *word_with_quotes, int *str_iter, t_shell *shell)
{
	char	*old_word_with_quotes;

	old_word_with_quotes = word_with_quotes;
	word_with_quotes = expansion_status(old_word_with_quotes, str_iter, shell);
	ms_free(old_word_with_quotes);
	old_word_with_quotes = NULL;
	return (word_with_quotes);
}
