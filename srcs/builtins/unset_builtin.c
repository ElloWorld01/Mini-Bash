/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:36:39 by elombard          #+#    #+#             */
/*   Updated: 2023/12/12 18:19:37 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static int	unset_env_alr_exist(char *env_name, char *new_env_name)
{
	char	mode;
	int		i;

	i = 0;
	mode = '=';
	if (!env_name || !new_env_name || ft_strchr(new_env_name, '=') != NULL)
		return (FALSE);
	if (ft_strchr(env_name, '=') == NULL)
		mode = '\0';
	while (env_name[i] != mode)
	{
		if (env_name[i] - new_env_name[i] != 0)
			return (FALSE);
		i++;
	}
	if (mode == '\0' && (env_name[i] != '\0' || new_env_name[i] != '\0'))
		return (FALSE);
	if (mode == '=' && ((env_name[i] == '\0' && new_env_name[i] == '\0')
			|| (env_name[i] == '=' && new_env_name[i] == '=')
			|| (env_name[i] == '=' && new_env_name[i] == '\0')
			|| (env_name[i] == '\0' && new_env_name[i] == '=')))
		return (TRUE);
	if (mode == '=')
		return (FALSE);
	return (TRUE);
}

static int	unset_check_if_found(char **env, char *to_delete)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (unset_env_alr_exist(env[i], to_delete) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	**unset_delete_arg(char **input, char *to_delete)
{
	char	**result;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (unset_check_if_found(input, to_delete) == FALSE)
		return (input);
	while (input[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i));
	if (!result)
		return (NULL);
	result[i - 1] = NULL;
	i = -1;
	while (input[++i] != NULL)
	{
		if (unset_env_alr_exist(input[i], to_delete) == FALSE)
			result[j++] = ft_strdup(input[i]);
		free (input[i]);
		input[i] = NULL;
	}
	free (input);
	input = NULL;
	return (result);
}

int	unset_builtin(t_shell *shell, char **command_with_args)
{
	char	*args;
	int		i;

	shell->exit_status = 0;
	i = 0;
	if (!shell->env || !shell->env[0])
		return (CMD_SUCCESS);
	while (command_with_args[++i] != NULL)
	{
		args = ft_strdup(command_with_args[i]);
		if (args)
			shell->env = unset_delete_arg(shell->env, args);
		free (args);
		args = NULL;
	}
	return (CMD_SUCCESS);
}
