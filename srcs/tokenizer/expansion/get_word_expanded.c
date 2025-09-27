/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_expanded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:02:53 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:37:08 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*get_word_expanded(t_shell *shell, char *line, size_t *str_iter)
{
	char	*word;
	char	*word_with_quotes_expanded;

	word = get_word_until_delimiters(line, DELIMITERS_TOKENS, str_iter, shell);
	word_with_quotes_expanded = expand_variables_if_any(word, shell);
	return (word_with_quotes_expanded);
}
