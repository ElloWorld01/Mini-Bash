/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:23:52 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 21:19:34 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	heredoc_wait_end(const int *pipe_heredoc, pid_t child_pid)
{
	int	stat;

	close(pipe_heredoc[PIPE_WRITE]);
	waitpid(child_pid, &stat, 0);
	if (WIFEXITED(stat))
		stat = WEXITSTATUS(stat);
	return (stat);
}

static int	check_stop_word(char *line, char *stop_word, t_shell *shell)
{
	char	*copy_line;
	char	*pointer_to_newline;

	copy_line = ch_strdup(line, shell);
	pointer_to_newline = ft_strchr(copy_line, '\n');
	if (pointer_to_newline != NULL)
		*pointer_to_newline = '\0';
	if (copy_line == NULL || ft_strcmp(copy_line, stop_word) == 0)
	{
		free(copy_line);
		return (TRUE);
	}
	free(copy_line);
	return (FALSE);
}

static void	heredoc_get_lines(char *stop_word, const int *pipe_heredoc,
						t_shell *shell)
{
	char	*line;
	char	*line_expanded;

	close(pipe_heredoc[PIPE_READ]);
	while (TRUE)
	{
		signal(SIGINT, heredoc_signal_handler);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || heredoc_stop_signal()
			|| check_stop_word(line, stop_word, shell))
		{
			if (line == NULL)
				printerr_heredoc_eof(stop_word);
			free(line);
			close(pipe_heredoc[PIPE_WRITE]);
			if (heredoc_stop_signal())
				ch_exit(shell, CHILD_HEREDOC_INTERRUPT);
			ch_exit(shell, 0);
		}
		line_expanded = expand_variables_if_any(line, shell);
		ft_putstr_fd(line_expanded, pipe_heredoc[PIPE_WRITE]);
		free(line_expanded);
	}
}

static int	heredoc_parent_child(pid_t pid, int *pipe_heredoc,
								char *stop_word, t_shell *shell)
{
	int	heredoc_status;

	if (pid == 0)
	{
		close_all_heredocs_except_last(shell->exec->exec_list);
		heredoc_get_lines(stop_word, pipe_heredoc, shell);
	}
	else
	{
		heredoc_status = heredoc_wait_end(pipe_heredoc, pid);
		if (heredoc_status == CHILD_HEREDOC_INTERRUPT)
		{
			close_all_heredocs_except_last(shell->exec->exec_list);
			close(pipe_heredoc[PIPE_READ]);
			shell->exit_status = CODE_130_INTERRUPT;
			return (PARENT_HEREDOC_INTERRUPT);
		}
	}
	return (pipe_heredoc[PIPE_READ]);
}

int	do_current_heredoc(char *stop_word, t_shell *shell)
{
	int		pipe_heredoc[2];
	pid_t	pid;

	if (pipe(pipe_heredoc) == -1)
		return (PARENT_HEREDOC_FAIL);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_heredoc[PIPE_READ]);
		close(pipe_heredoc[PIPE_WRITE]);
		return (PARENT_HEREDOC_FAIL);
	}
	return (heredoc_parent_child(pid, pipe_heredoc, stop_word, shell));
}
