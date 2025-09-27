/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:18:57 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:26:55 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	check_infiles(t_token_list *current_node)
{
	t_token_list	*tmp;

	tmp = current_node;
	while (tmp)
	{
		if (tmp->type == TOKEN_INPUT_REDIRECT)
		{
			if (tmp->next && tmp->next->type == TOKEN_WORD)
				tmp->next->type = TOKEN_INFILE;
		}
		if (tmp->type == TOKEN_HEREDOC_REDIRECT)
		{
			if (tmp->next && tmp->next->type == TOKEN_WORD)
				tmp->next->type = TOKEN_HEREDOC_WORD;
		}
		tmp = tmp->next;
	}
}

static void	check_outfiles(t_token_list *current_node)
{
	t_token_list	*tmp;

	tmp = current_node;
	while (tmp)
	{
		if (tmp->type == TOKEN_OUTPUT_REDIRECT)
		{
			if (tmp->next && tmp->next->type == TOKEN_WORD)
				tmp->next->type = TOKEN_OUTFILE_NORMAL;
		}
		if (tmp->type == TOKEN_APPEND_REDIRECT)
		{
			if (tmp->next && tmp->next->type == TOKEN_WORD)
				tmp->next->type = TOKEN_OUTFILE_APPEND;
		}
		tmp = tmp->next;
	}
}

static void	update_type_for_files(t_shell *shell)
{
	t_token_list	*current_node;

	current_node = shell->tokenizer->head;
	check_infiles(current_node);
	check_outfiles(current_node);
}

static t_token_list	*tokenize_line(t_shell *shell)
{
	t_token_list	*head;
	size_t			line_len;

	head = NULL;
	line_len = ft_strlen(shell->line_readed_dup);
	process_line(shell, &head, line_len);
	return (head);
}

void	do_tokenize(t_shell *shell)
{
	shell->tokenizer->head = tokenize_line(shell);
	update_type_for_files(shell);
}
