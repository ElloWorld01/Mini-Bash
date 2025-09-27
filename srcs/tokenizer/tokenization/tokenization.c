/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:39:21 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 20:19:00 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	tokenize(t_token_list **head, char *token, t_shell *shell)
{
	push_node(head, token, get_token_type_from_string(token, shell), shell);
}

void	handle_token(t_token_list **head, char *token, t_shell *shell)
{
	if (token == NULL)
		return ;
	tokenize(head, token, shell);
}

char	*get_token(t_shell *shell, char *line, size_t *str_iter)
{
	char	*word_with_quotes_expanded;
	char	*final_word;

	while (line[*str_iter])
	{
		if (ft_strchr(DELIMITERS_TOKENS, line[*str_iter]) != NULL)
		{
			if (is_normal_operator(line[*str_iter]))
				return (get_normal_operator(line, str_iter, shell));
		}
		else
		{
			word_with_quotes_expanded = get_word_expanded(
					shell, line, str_iter);
			if (word_with_quotes_expanded == NULL)
				return (NULL);
			final_word = remove_quotes_from_word(
					word_with_quotes_expanded, shell);
			ms_free(word_with_quotes_expanded);
			return (final_word);
		}
		*str_iter += 1;
	}
	return (NULL);
}
