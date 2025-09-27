/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:36:39 by elombard          #+#    #+#             */
/*   Updated: 2023/12/09 03:40:41 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	check_tiret_n(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (FALSE);
	if (ft_strlen(arg) == 1)
		return (FALSE);
	i = 1;
	while (arg[i])
	{
		if (arg[i++] != 'n')
			return (FALSE);
	}
	return (TRUE);
}

void	echo_sub(char **args, int skip_nl)
{
	int	i;
	int	must_print;

	i = 0;
	must_print = 0;
	while (args[++i])
	{
		if (check_tiret_n(args[1]) == TRUE && skip_nl == 0)
		{
			skip_nl = 1;
			continue ;
		}
		if (skip_nl == 1 && check_tiret_n(args[i]) == TRUE
			&& must_print == 0)
			continue ;
		else
			must_print = 1;
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	if (check_tiret_n(args[1]) == FALSE && skip_nl == 0)
		printf("\n");
}

int	echo_builtin(t_shell *shell, char **command_with_args)
{
	int		skip_nl;

	skip_nl = 0;
	if (command_with_args[1] == NULL)
	{
		printf("\n");
		return (shell->exit_status = 0);
	}
	echo_sub(command_with_args, skip_nl);
	return (shell->exit_status = 0);
}
