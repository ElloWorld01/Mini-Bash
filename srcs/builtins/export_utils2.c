/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:42:18 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/12 16:54:07 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	export_sub_builtin(t_shell *shell, char **command_with_args, int i)
{
	int	j;

	j = -1;
	while (shell->env[++j])
	{
		if (export_env_alr_exist(shell->env[j], command_with_args[i]) == TRUE)
		{
			export_replace_at(shell, command_with_args[i], j);
			return ;
		}
	}
	export_append(shell, command_with_args[i]);
}

int	export_sub_print(char **sorted_env, int i, int j, int equal_quote)
{
	while (sorted_env[i][++j] != '\0')
	{
		if (j == 0)
			printf("declare -x ");
		printf("%c", sorted_env[i][j]);
		if (sorted_env[i][j] == '=' && equal_quote == FALSE)
			printf("\"");
		if (sorted_env[i][j] == '=' && equal_quote == FALSE)
			equal_quote = TRUE;
	}
	return (equal_quote);
}

void	swap_entry(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	**sort_env(char **env)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (env[len] != NULL)
		len++;
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (strcmp(env[j], env[j + 1]) > 0)
				swap_entry(&env[j], &env[j + 1]);
		}
	}
	return (env);
}

void	free_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env);
	env = NULL;
}
