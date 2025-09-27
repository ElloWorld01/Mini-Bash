/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:00:29 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/12 18:18:13 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	export_replace_at(t_shell *shell, char *arg, int line)
{
	free (shell->env[line]);
	shell->env[line] = NULL;
	shell->env[line] = ft_strdup(arg);
	return ;
}

void	export_append(t_shell *shell, char *arg)
{
	if (!shell->env[0])
	{
		free(shell->env);
		shell->env = malloc(sizeof(char *) * 2);
		if (!shell->env)
			return ;
		shell->env[0] = ft_strdup(arg);
		shell->env[1] = NULL;
		return ;
	}
	shell->env = env_recreate_newline(shell->env, arg);
	return ;
}

int	export_env_alr_exist(char *env_name, char *new_env_name)
{
	char	mode;
	int		i;

	i = 0;
	mode = '=';
	if (!env_name || !new_env_name)
		return (FALSE);
	if (ft_strchr(env_name, '=') == NULL)
		mode = '\0';
	while (env_name[i] != mode)
	{
		if (env_name[i] - new_env_name[i] != 0)
			return (FALSE);
		i++;
	}
	if ((env_name[i] == '\0' && new_env_name[i] == '\0')
		|| (env_name[i] == '=' && new_env_name[i] == '=')
		|| (env_name[i] == '=' && new_env_name[i] == '\0')
		|| (env_name[i] == '\0' && new_env_name[i] == '='))
		return (TRUE);
	return (FALSE);
}

char	**env_recreate_newline(char **input, char *new_arg)
{
	char	**result;
	int		j;
	int		i;

	i = 0;
	while (input[i] != NULL)
		i++;
	j = i + 2;
	result = malloc(sizeof(char *) * (i + 2));
	if (!result)
		return (NULL);
	result[i + 1] = NULL;
	i = -1;
	while (++i != j - 2)
	{
		result[i] = ft_strdup(input[i]);
		free (input[i]);
		input[i] = NULL;
	}
	result[j - 2] = ft_strdup(new_arg);
	free (input);
	input = NULL;
	return (result);
}

int	export_parse(char *arg)
{
	char	*env_name;

	if (!arg)
		return (FALSE);
	if (ft_strchr(arg, '=') != NULL)
	{
		env_name = env_get_var_name(arg);
		if (is_valid_env_var_name(env_name) == TRUE)
		{
			free (env_name);
			env_name = NULL;
			return (TRUE);
		}
		free (env_name);
	}
	else
		if (is_valid_env_var_name(arg) == TRUE)
			return (TRUE);
	return (FALSE);
}
