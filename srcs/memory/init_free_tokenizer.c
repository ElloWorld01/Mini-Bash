/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:38:05 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:08:32 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	init_tokenizer(t_shell *shell)
{
	t_tokenizer	*tokenizer;

	tokenizer = ms_calloc(1, sizeof(t_tokenizer), shell);
	shell->tokenizer = tokenizer;
	shell->tokenizer->shell = shell;
	shell->tokenizer->head = NULL;
	shell->tokenizer->alter_word = NULL;
	shell->tokenizer->size = 0;
}

void	free_tokenizer(t_shell *shell)
{
	free_list(&shell->tokenizer->head);
	if (shell->tokenizer->alter_word != NULL)
	{
		ms_free(shell->tokenizer->alter_word->old_word);
		shell->tokenizer->alter_word->old_word = NULL;
		ms_free(shell->tokenizer->alter_word->new_word);
		shell->tokenizer->alter_word->new_word = NULL;
		ms_free(shell->tokenizer->alter_word);
		shell->tokenizer->alter_word = NULL;
	}
	free(shell->tokenizer);
	shell->tokenizer = NULL;
}
