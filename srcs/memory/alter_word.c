/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:36:20 by elombard          #+#    #+#             */
/*   Updated: 2023/10/17 15:39:41 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	init_alter_word(t_shell *shell, char *string, char *old_word,
			int old_word_position)
{
	shell->tokenizer->alter_word = ms_calloc(1, sizeof(t_alter_word), shell);
	shell->tokenizer->alter_word->string = string;
	shell->tokenizer->alter_word->old_word = old_word;
	shell->tokenizer->alter_word->old_word_position = old_word_position;
	shell->tokenizer->alter_word->new_word = NULL;
}

void	free_alter_word(t_shell *shell)
{
	ms_free(shell->tokenizer->alter_word->new_word);
	shell->tokenizer->alter_word->new_word = NULL;
	ms_free(shell->tokenizer->alter_word->old_word);
	shell->tokenizer->alter_word->old_word = NULL;
	ms_free(shell->tokenizer->alter_word);
	shell->tokenizer->alter_word = NULL;
}
