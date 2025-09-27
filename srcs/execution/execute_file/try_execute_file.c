/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_execute_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:25:58 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 21:21:31 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	check_recursive_file(char *line, char *filename, t_shell *shell)
{
	char	*filename_without_dot_slash;

	if (!has_dot_slash(line))
	{
		filename_without_dot_slash = remove_dot_slash(filename, shell);
		if (ft_strcmp(line, filename_without_dot_slash) == 0)
		{
			printerr_src_msg_ln(line, MSG_RECURSIVE_FILE);
			shell->exit_status = CODE_126_PRESENT_BUT_NOT_EXECUTABLE;
			ms_free(filename_without_dot_slash);
			return (TRUE);
		}
		ms_free(filename_without_dot_slash);
	}
	else
	{
		if (ft_strcmp(line, filename) == 0)
		{
			printerr_src_msg_ln(line, MSG_RECURSIVE_FILE);
			shell->exit_status = CODE_126_PRESENT_BUT_NOT_EXECUTABLE;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	execute_lines_of_file(t_shell *shell, char *filename, int fd)
{
	char	*line;
	char	*line_without_nl;

	signal(SIGINT, sigint_execute_file);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			ms_free(line);
			ms_free(filename);
			close(fd);
			ch_exit(shell, shell->exit_status);
		}
		line_without_nl = remove_newline_at_end(line, shell);
		ms_free(line);
		if (!check_recursive_file(line_without_nl, filename, shell))
			child_execute_file_command(shell, line_without_nl, filename, fd);
		ms_free(line_without_nl);
	}
}

void	try_to_open_file(char *filename, t_shell *shell)
{
	int		fd;
	char	*new_cmd;

	if (access(filename, X_OK) != 0 || access(filename, R_OK) != 0)
	{
		printerr_src_msg_ln(filename, MSG_PERM_DENIED);
		ch_exit(shell, CODE_126_PRESENT_BUT_NOT_EXECUTABLE);
	}
	new_cmd = remove_dot_slash(filename, shell);
	fd = open(new_cmd, O_RDONLY);
	ms_free(new_cmd);
	if (fd != -1)
	{
		execute_lines_of_file(shell, filename, fd);
	}
}

void	try_execute_file(char *filename, t_shell *shell)
{
	if (is_directory(filename))
	{
		printerr_src_msg_ln(filename, MSG_IS_A_DIR);
		ch_exit(shell, CODE_126_PRESENT_BUT_NOT_EXECUTABLE);
	}
	try_to_open_file(filename, shell);
	printerr_src_msg_ln(filename, MSG_PERM_DENIED);
	ms_free(filename);
	ch_exit(shell, CODE_126_PRESENT_BUT_NOT_EXECUTABLE);
}
