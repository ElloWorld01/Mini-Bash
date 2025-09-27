/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:09:41 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 01:02:13 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static t_token_list	*create_new_node(char *str, t_token_type token,
										t_shell *shell)
{
	t_token_list	*node;

	node = ms_malloc(sizeof(t_token_list), shell);
	node->value = str;
	node->next = NULL;
	node->type = token;
	return (node);
}

void	push_node(t_token_list **head, char *token, t_token_type type,
					t_shell *shell)
{
	t_token_list	*new_node;
	t_token_list	*tmp;

	new_node = create_new_node(token, type, shell);
	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	shell->tokenizer->size += 1;
}

void	free_list(t_token_list **node)
{
	t_token_list	*tmp;

	if (*node == NULL)
		return ;
	while (*node != NULL)
	{
		tmp = *node;
		*node = (*node)->next;
		ms_free(tmp->value);
		tmp->value = NULL;
		ms_free(tmp);
		tmp = NULL;
	}
	tmp = NULL;
}
