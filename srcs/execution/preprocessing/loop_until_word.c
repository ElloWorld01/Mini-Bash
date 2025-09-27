/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_until_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:48:42 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:38:29 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

t_list_redirections	*add_redirection(
		t_token_list *tokenizer_list, t_list_redirections *list_redirections,
		t_list_redirections **exec_list_redirections)
{
	if (list_redirections == NULL)
	{
		list_redirections = ft_calloc(1, sizeof(t_list_redirections));
		*exec_list_redirections = list_redirections;
	}
	else
	{
		list_redirections->next = ft_calloc(1, sizeof(t_list_redirections));
		list_redirections = list_redirections->next;
	}
	list_redirections->filename = ft_strdup(tokenizer_list->value);
	list_redirections->type = tokenizer_list->type;
	return (list_redirections);
}

void	go_to_next_command(t_exec_list **exec_list,
						t_list_redirections **current_in_redirections,
						t_list_redirections **current_out_redirections)
{
	(*exec_list)->next = init_exec_list_type();
	(*exec_list)->command_is_present = FALSE;
	(*exec_list) = (*exec_list)->next;
	(*current_in_redirections) = NULL;
	(*current_out_redirections) = NULL;
}

void	loop_until_word(t_list_redirections **current_in_redirections,
						t_list_redirections **current_out_redirections,
						t_token_list **token_list, t_exec_list **exec_list)
{
	while ((*token_list) != NULL && (*token_list)->type != TOKEN_WORD)
	{
		if ((*token_list)->type == TOKEN_INFILE
			|| (*token_list)->type == TOKEN_HEREDOC_WORD)
		{
			(*current_in_redirections) = add_redirection(
					(*token_list), (*current_in_redirections),
					&(*exec_list)->in_redirections);
		}
		if ((*token_list)->type == TOKEN_OUTFILE_NORMAL
			|| (*token_list)->type == TOKEN_OUTFILE_APPEND)
		{
			(*current_out_redirections) = add_redirection(
					(*token_list), (*current_out_redirections),
					&(*exec_list)->out_redirections);
		}
		if ((*token_list)->type == TOKEN_PIPE)
			go_to_next_command(exec_list, current_in_redirections,
				current_out_redirections);
		(*token_list) = (*token_list)->next;
	}
}
