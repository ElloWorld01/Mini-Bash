/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:05:33 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:29 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pipe_files			t_pipe_files;
typedef struct s_exec_list			t_exec_list;
typedef struct s_exec				t_exec;
typedef struct s_token_list			t_token_list;
typedef struct s_alter_word			t_alter_word;
typedef struct s_tokenizer			t_tokenizer;
typedef struct s_shell				t_shell;
typedef struct s_list_redirections	t_list_redirections;
typedef struct s_cd					t_cd;

struct s_list_redirections
{
	char						*filename;
	struct s_list_redirections	*next;
	t_token_type				type;
};

struct s_exec_list
{
	t_list_redirections	*in_redirections;
	t_list_redirections	*out_redirections;
	int					heredoc_read_fd;
	int					command_is_present;
	char				**command_with_args;
	struct s_exec_list	*next;
};

struct s_pipe_files
{
	int	pipefds[2];
	int	dupfds[2];
	int	savefd;
};

struct s_exec
{
	char			**env;
	t_pipe_files	*pipe_files;
	int				pipes_count;
	int				*commands_count;
	int				*childs_pids;
	char			*path;
	int				pipe_position;
	t_exec_list		*exec_list;
	t_shell			*shell;
};

struct s_token_list
{
	char				*value;
	t_token_type		type;
	struct s_token_list	*next;
};

struct s_alter_word
{
	char	*string;
	char	*old_word;
	char	*new_word;
	int		old_word_position;
};

struct s_tokenizer
{
	t_token_list	*head;
	t_alter_word	*alter_word;
	int				size;
	int				is_operator;
	t_shell			*shell;
};

struct s_cd
{
	char			*data;
	struct s_cd		*prev;
	struct s_cd		*next;
};

struct s_shell
{
	char		*line_readed;
	char		*line_readed_dup;
	char		*line_history_dup_check;
	t_tokenizer	*tokenizer;
	t_exec		*exec;
	char		**env;
	int			argc;
	char		**argv;
	int			exit_status;
	t_cd		*cd_tiret;
	t_cd		*cd_split_path;
	int			tiret;
	int			absolu;
	int			cd_index;
	int			cd_instruction_len;
};

#endif
