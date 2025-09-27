/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:30:52 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:30:51 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*replace_word(t_alter_word *alter_word, t_shell *shell)
{
	size_t	dollar_word_len;
	char	*beginning_of_line;
	char	*total_line;

	beginning_of_line = ms_strndup(alter_word->string,
			alter_word->old_word_position, shell);
	dollar_word_len = ft_strlen(alter_word->old_word);
	alter_word->string += dollar_word_len + alter_word->old_word_position + 1;
	total_line = ms_strjoin(beginning_of_line, alter_word->new_word, shell);
	ms_free(alter_word->new_word);
	ms_free(beginning_of_line);
	alter_word->new_word = total_line;
	alter_word->string = ms_strjoin(
			alter_word->new_word, alter_word->string, shell);
	return (alter_word->string);
}

char	*remove_word(t_alter_word *alter_word, t_shell *shell, int *str_iter)
{
	char	*beginning_of_line;

	beginning_of_line = ms_strndup(
			alter_word->string, alter_word->old_word_position, shell);
	alter_word->string += alter_word->old_word_position
		+ ft_strlen(alter_word->old_word) + 1;
	alter_word->string = ms_strjoin(
			beginning_of_line, alter_word->string, shell);
	ms_free(beginning_of_line);
	if (alter_word->string[0] == '\0')
	{
		free(alter_word->string);
		alter_word->string = NULL;
	}
	*str_iter -= 1;
	return (alter_word->string);
}

char	*replace_or_remove_word_if_no_substitute(t_alter_word *alter_word,
			t_shell *shell, int *str_iter)
{
	if (alter_word->new_word == NULL)
		alter_word->string = remove_word(alter_word, shell, str_iter);
	else
		alter_word->string = replace_word(alter_word, shell);
	return (alter_word->string);
}
