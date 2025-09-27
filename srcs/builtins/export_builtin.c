/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:24:10 by elombard          #+#    #+#             */
/*   Updated: 2023/12/09 03:41:53 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	is_valid_env_var_name(const char *str)
{
	char	c;
	int		i;

	if (str == NULL || str[0] == '\0')
		return (FALSE);
	if (ft_isdigit(str[0]))
		return (FALSE);
	i = -1;
	while (str[++i] != '\0')
	{
		c = str[i];
		if (!(ft_isalpha(c) || ft_isdigit(c) || c == '_'))
			return (FALSE);
	}
	return (TRUE);
}

void	export_print(t_shell *shell)
{
	char	**sorted_env;
	int		equal_quote;
	int		i;
	int		j;

	if (!shell->env || !shell->env[0])
		return ;
	sorted_env = sort_env(shell->env);
	i = -1;
	while (sorted_env[++i])
	{
		equal_quote = FALSE;
		j = -1;
		equal_quote = export_sub_print(sorted_env, i, j, equal_quote);
		if (equal_quote == TRUE)
			printf("\"");
		printf("\n");
	}
	free_env(sorted_env);
}

int	export_builtin(t_shell *shell, char **command_with_args)
{
	int	i;

	if (!command_with_args[1])
	{
		export_print(shell);
		return (CMD_SUCCESS);
	}
	i = 0;
	while (command_with_args[++i])
	{
		if (export_parse(command_with_args[i]) == FALSE)
		{
			printf("❌ " YELLOW NAME_LOWER " : export: " );
			printf(RED "%s \n" RESET, command_with_args[i]);
			continue ;
		}
		export_sub_builtin(shell, command_with_args, i);
	}
	return (CMD_SUCCESS);
}
