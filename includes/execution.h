/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:42:20 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 18:49:39 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

char		*get_command(char *cmd, char *path, t_shell *shell);

char		*get_path_line_in_env(char **envp);
void		split_path(char *path, char ***paths, t_shell *shell);
int			find_path(char ***paths, char *cmd, char **test_cmd_path,
				t_shell *shell);

void		execute_command(t_exec *exec, char *cmd, char ***args);

void		free_array_of_char_array(char **array);
void		free_close(char *cmd, char **args);

int			execution(t_shell *shell);

int			number_of_command_words(t_token_list *current);
int			number_of_commands(t_token_list *head);
void		token_list_to_exec(t_shell *shell);

void		loop_until_word(t_list_redirections **current_in_redirections,
				t_list_redirections **current_out_redirections,
				t_token_list **token_list, t_exec_list **exec_list);

int			redirections(t_exec_list current_cmd);
int			redirect_input(t_list_redirections *current_redirection,
				int heredoc_fd);
int			redirect_output(t_list_redirections *current_redirection);
int			redirect_heredoc(int fd);

void		parent_handle_current_pipe(t_exec *exec);
void		child_dup_and_close_pipe(t_exec *exec);
void		parent_close_current_unused_pipe_files(t_exec *exec);
void		parent_init_pipe_files(t_exec *exec);
void		dup_current_pipe(t_exec *exec);
void		close_duped_pipe(t_exec *exec);

int			can_use_builtin(char *cmd);
int			execute_builtins(t_shell *shell, char **command_with_args);
int			do_heredocs(t_exec *exec);
pid_t		child_current_cmd(t_exec *exec, t_exec_list *current_cmd);
void		alloc_childs_pids_array(t_exec *exec);
int			check_only_builtin(t_exec *exec);
void		wait_childs(t_exec exec, int *stat);
void		do_execution(t_shell *shell);
int			compare_exactly(char *cmd, char *string);
int			execute_child_builtins(t_shell *shell, char **command_with_args);
int			execute_parent_builtins(t_shell *shell, char **command_with_args);
int			do_current_heredoc(char *stop_word, t_shell *shell);
int			get_correct_return_code(int return_code);
int			close_current_and_next_heredocs(t_exec_list *current_cmd);
int			close_all_heredocs_except_last(t_exec_list *current_cmd);
t_exec_list	*init_exec_list_type(void);

void		close_heredoc_fd_if_present(int fd_heredoc);
int			has_dot_slash(const char *filename);
int			is_directory(char *filename);

void		try_execute_file(char *filename, t_shell *shell);
void		sigint_execute_file(int sig);
char		*remove_dot_slash(char *cmd, t_shell *shell);
char		*remove_newline_at_end(char *line, t_shell *shell);
void		child_execute_file_command(t_shell *shell, char *command_line,
				char *filename, int fd);

#endif