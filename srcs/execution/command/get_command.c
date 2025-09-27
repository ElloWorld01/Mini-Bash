/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:11:35 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 20:14:08 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static char	*is_access_no_path(char ***paths, char *cmd_without_args)
{
	if (access(cmd_without_args, X_OK) == 0)
	{
		free_array_of_char_array(*paths);
		return (cmd_without_args);
	}
	return (NULL);
}

char	*get_command(char *cmd, char *path, t_shell *shell)
{
	char	**paths;
	char	*cmd_and_path;
	int		is_command_executable;
	char	*command_dup;

	split_path(path, &paths, shell);
	cmd_and_path = NULL;
	is_command_executable = find_path(&paths, cmd, &cmd_and_path, shell);
	if (is_command_executable)
		return (cmd_and_path);
	if (is_access_no_path(&paths, cmd) != NULL)
	{
		command_dup = ft_strdup(cmd);
		return (command_dup);
	}
	free_array_of_char_array(paths);
	return (NULL);
}
