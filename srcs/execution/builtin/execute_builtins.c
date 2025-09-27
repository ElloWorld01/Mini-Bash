/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:19 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:42:00 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	execute_child_builtins(t_shell *shell, char **command_with_args)
{
	char	*cmd;

	cmd = command_with_args[0];
	if (compare_exactly(cmd, "echo"))
		return (echo_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "env"))
		return (env_builtin(shell));
	if (compare_exactly(cmd, "export") && command_with_args[1] == NULL)
		return (export_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "pwd"))
		return (pwd_builtin());
	return (-1);
}

int	execute_parent_builtins(t_shell *shell, char **command_with_args)
{
	char	*cmd;

	cmd = command_with_args[0];
	if (compare_exactly(cmd, "cd"))
		return (cd_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "exit"))
		return (ms_exit_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "export") && command_with_args[1] != NULL)
		return (export_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "unset"))
		return (unset_builtin(shell, command_with_args));
	return (-1);
}

int	execute_builtins(t_shell *shell, char **command_with_args)
{
	char	*cmd;

	cmd = command_with_args[0];
	if (compare_exactly(cmd, "cd"))
		return (cd_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "echo"))
		return (echo_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "env"))
		return (env_builtin(shell));
	if (compare_exactly(cmd, "exit"))
		return (ch_exit_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "export"))
		return (export_builtin(shell, command_with_args));
	if (compare_exactly(cmd, "pwd"))
		return (pwd_builtin());
	if (compare_exactly(cmd, "unset"))
		return (unset_builtin(shell, command_with_args));
	return (CMD_FAILURE);
}
