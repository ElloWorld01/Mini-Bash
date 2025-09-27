/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_after_dollar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:10:33 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:38:37 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	is_env_name_char_allowed(char c)
{
	return (ft_isdigit(c) || ft_isalpha(c) || c == '_');
}

static int	name_conditions(char c, size_t iter)
{
	if (iter == 0 && !ft_isalpha(c) && c != '_')
	{
		return (2);
	}
	else if (is_env_name_char_allowed(c))
		return (0);
	return (1);
}

char *
	get_word_after_dollar(size_t str_iter, char *word_to_expand, t_shell *shell)
{
	size_t	iter;
	char	*dollar_word;

	iter = str_iter + 1;
	dollar_word = get_word_until_condition(
			word_to_expand, name_conditions, &iter, shell);
	return (dollar_word);
}
