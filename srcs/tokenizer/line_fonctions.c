/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:02:53 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:54 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	process_line(t_shell *shell, t_token_list **head, size_t line_len)
{
	size_t	str_iter;
	char	*token;

	str_iter = 0;
	while (str_iter < line_len)
	{
		shell->tokenizer->is_operator = FALSE;
		token = get_token(shell, shell->line_readed_dup, &str_iter);
		handle_token(head, token, shell);
	}
}

void	get_command_line(t_shell *shell)
{
	shell->line_readed = readline(PROMPT);
	if (shell->line_readed == NULL)
		ms_handle_error(shell, NO_MESSAGE);
	shell->line_readed_dup = ms_strdup(shell, shell->line_readed);
}
