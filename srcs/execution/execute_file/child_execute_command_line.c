/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execute_command_line.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:51:21 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 17:35:52 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	child_execute_command_line(t_shell *shell, char *command_line)
{
	free_shell_vars(shell);
	initiate_shell_vars(shell);
	init_signals();
	shell->line_readed = command_line;
	if (shell->line_readed == NULL)
		ch_handle_error(shell, NO_MESSAGE);
	shell->line_readed_dup = ms_strdup(shell, shell->line_readed);
	if (do_parsing_line(shell) == TRUE)
	{
		do_tokenize(shell);
		do_execution(shell);
	}
	else
		shell->exit_status = 2;
	ch_exit(shell, shell->exit_status);
}

void	child_execute_file_command(t_shell *shell, char *command_line,
				char *filename, int fd)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		printerr_shell_ln("fork() failed, stopping execution");
		close(fd);
		ms_free(filename);
		ch_exit(shell, EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		close(fd);
		ms_free(filename);
		child_execute_command_line(shell, command_line);
	}
	else
	{
		waitpid(child_pid, &shell->exit_status, 0);
		shell->exit_status = get_correct_return_code(shell->exit_status);
	}
}
