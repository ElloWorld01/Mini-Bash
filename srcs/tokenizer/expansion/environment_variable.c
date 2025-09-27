/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:29:59 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:38:14 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*get_env_var(char *word, t_shell *shell)
{
	char	**env;
	char	*env_word_value;
	char	*word_plus_equal;

	env = shell->env;
	word_plus_equal = ms_strjoin(word, "=", shell);
	while (*env)
	{
		if (found_env_var_with_word(env, word_plus_equal))
		{
			ms_free(word_plus_equal);
			env_word_value = get_value_of_env_word_key(word, env);
			return (env_word_value);
		}
		env += 1;
	}
	ms_free(word_plus_equal);
	return (NULL);
}

char	*get_value_of_env_word_key(const char *word, char *const *env)
{
	return (ms_strndup(*env + ft_strlen(word) + 1,
			ft_strlen(*env) - ft_strlen(word) - 1, NULL));
}

int	found_env_var_with_word(char *const *env, const char *word_plus_equal)
{
	return (ft_strncmp(*env, word_plus_equal, ft_strlen(word_plus_equal)) == 0);
}
