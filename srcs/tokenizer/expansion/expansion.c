/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:32:32 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:36:58 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	adjust_str_iter_if_end_of_string(int *str_iter, const char *word)
{
	if (word != NULL && *str_iter >= 0 && word[*str_iter] == '\0')
		*str_iter -= 1;
}

static char	*alter_word(int *str_iter, t_shell *shell, char *word)
{
	char	*word_expanded;

	shell->tokenizer->alter_word->new_word = get_env_var(word, shell);
	word_expanded = replace_or_remove_word_if_no_substitute(
			shell->tokenizer->alter_word, shell, str_iter);
	adjust_str_iter_if_end_of_string(str_iter, word_expanded);
	return (word_expanded);
}

char	*expansion(char *word_to_expand, int *str_iter, t_shell *shell)
{
	char	*dollar_word;
	char	*word_expanded;
	int		init_iter;

	init_iter = *str_iter;
	dollar_word = get_word_after_dollar(*str_iter, word_to_expand, shell);
	init_alter_word(shell, word_to_expand, dollar_word, init_iter);
	word_expanded = alter_word(str_iter, shell, dollar_word);
	free_alter_word(shell);
	return (word_expanded);
}
