/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:29:47 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:53:25 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*get_path_line_in_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	split_path(char *path, char ***paths, t_shell *shell)
{
	*paths = ft_split(path, ':');
	if (paths == NULL)
		ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
}

static int	is_command_executable(char *test_cmd_path, char ***paths)
{
	if (access(test_cmd_path, X_OK) == 0)
	{
		free_array_of_char_array(*paths);
		return (1);
	}
	return (0);
}

char	*get_current_path(char **const *paths, t_shell *shell,
						char *current_path, int i)
{
	current_path = ft_strjoin((*paths)[i], "/");
	if (!current_path)
	{
		free_array_of_char_array(*paths);
		ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	}
	return (current_path);
}

int	find_path(char ***paths, char *cmd, char **test_cmd_path, t_shell *shell)
{
	char	*current_path;
	int		i;

	i = 0;
	if (!(*paths))
		return (FALSE);
	while ((*paths)[i] != NULL)
	{
		current_path = get_current_path(paths, shell, current_path, i);
		*test_cmd_path = ft_strjoin(current_path, cmd);
		ms_free(current_path);
		if (!(*test_cmd_path))
		{
			free_array_of_char_array(*paths);
			ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
		}
		if (is_command_executable(*test_cmd_path, paths))
			return (TRUE);
		ms_free(*test_cmd_path);
		++i;
	}
	return (FALSE);
}
