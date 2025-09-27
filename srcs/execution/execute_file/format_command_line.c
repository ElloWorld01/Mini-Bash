/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:27:51 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 21:18:37 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

char	*remove_dot_slash(char *cmd, t_shell *shell)
{
	char	*new_cmd;
	int		dot_slash_len;
	int		iter;

	if (cmd[0] == '\0' || cmd[1] == '\0' || cmd[0] != '.' || cmd[1] != '/')
		return (ch_strdup(cmd, shell));
	dot_slash_len = 2;
	iter = 0;
	new_cmd = ch_malloc((ft_strlen(cmd) - dot_slash_len) + 1, shell);
	while (cmd[dot_slash_len])
	{
		new_cmd[iter] = cmd[dot_slash_len];
		++dot_slash_len;
		++iter;
	}
	new_cmd[iter] = '\0';
	return (new_cmd);
}

char	*remove_newline_at_end(char *line, t_shell *shell)
{
	int		iter;
	char	*new_line;

	iter = 0;
	new_line = ch_malloc(ft_strlen(line), shell);
	while (line[iter])
	{
		new_line[iter] = line[iter];
		++iter;
	}
	new_line[iter - 1] = '\0';
	return (new_line);
}
