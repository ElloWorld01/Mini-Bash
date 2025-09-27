/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_until_delimiters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:47:36 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:49:34 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*get_word_until_delimiters(char *line, char *delimiters,
			size_t *str_iter, t_shell *shell)
{
	char	*word;
	int		word_len;
	size_t	init_iter;

	if (line[*str_iter] == '\0')
		return (NULL);
	init_iter = *str_iter;
	word_len = get_word_length_until_delimiters(line, delimiters, str_iter);
	word = ms_strndup(line + init_iter, word_len, shell);
	return (word);
}

char *
	get_word_until_condition(char *line, int condition_stop(char, size_t),
							size_t *iter, t_shell *shell)
{
	char	*word;
	int		word_len;
	size_t	init_iter;

	if (line[*iter] == '\0')
		return (NULL);
	init_iter = *iter;
	word_len = get_word_length_until_condition(line, condition_stop, iter);
	word = ms_strndup(line + init_iter, word_len, shell);
	return (word);
}
