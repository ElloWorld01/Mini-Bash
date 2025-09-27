/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:28:20 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 18:22:01 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	get_exit_status_atoll(char *str)
{
	long long	exit_status;

	if (check_long_long(str) == FALSE)
	{
		printerr_shell("exit: ");
		printerr(str);
		printerr(": numeric argument required\n");
		return (2);
	}
	exit_status = ft_atoll(str);
	if (exit_status < 0)
		return ((int)(256 + (exit_status % 256)));
	else
		return ((int)(exit_status % 256));
}

int	ms_exit_builtin(t_shell *shell, char **command_with_args)
{
	printerr_ln("exit");
	if (args_counter(command_with_args) > 2)
	{
		printerr_shell_ln("exit: too many arguments");
		shell->exit_status = CMD_FAILURE;
		return (CMD_FAILURE);
	}
	else if (args_counter(command_with_args) == 2)
	{
		shell->exit_status = get_exit_status_atoll(command_with_args[1]);
		ms_exit(shell, shell->exit_status, FALSE);
		return (shell->exit_status);
	}
	ms_exit(shell, CMD_SUCCESS, FALSE);
	return (CMD_SUCCESS);
}

int	ch_exit_builtin(t_shell *shell, char **command_with_args)
{
	if (args_counter(command_with_args) > 2)
	{
		printerr_shell_ln("exit: too many arguments");
		shell->exit_status = CMD_FAILURE;
		return (CMD_FAILURE);
	}
	else if (args_counter(command_with_args) == 2)
	{
		shell->exit_status = get_exit_status_atoll(command_with_args[1]);
		ch_exit(shell, shell->exit_status);
		return (shell->exit_status);
	}
	ch_exit(shell, CMD_SUCCESS);
	return (CMD_SUCCESS);
}
