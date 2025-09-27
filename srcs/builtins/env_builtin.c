/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:36:39 by elombard          #+#    #+#             */
/*   Updated: 2023/12/09 02:57:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

char	*env_get_var_name(char *arg)
{
	char	*var_name;
	int		i;

	if (!arg)
		return (NULL);
	if (ft_strchr(arg, '=') == NULL)
		return (ft_strdup(arg));
	i = 0;
	while (arg[i] != '=')
		i++;
	var_name = malloc(sizeof(char) * (i + 1));
	if (!var_name)
		return (NULL);
	i = -1;
	while (arg[++i] != '=')
		var_name[i] = arg[i];
	var_name[i] = '\0';
	return (var_name);
}

int	env_parse(char *arg)
{
	char	*env_name;

	if (!arg)
		return (FALSE);
	if (ft_strchr(arg, '=') == NULL)
		return (FALSE);
	env_name = env_get_var_name(arg);
	if (is_valid_env_var_name(env_name) == TRUE)
	{
		free(env_name);
		env_name = NULL;
		return (TRUE);
	}
	free(env_name);
	env_name = NULL;
	return (FALSE);
}

int	env_builtin(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->env[++i])
	{
		if (env_parse(shell->env[i]) == TRUE)
			printf("%s\n", shell->env[i]);
	}
	return (CMD_SUCCESS);
}
