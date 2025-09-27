/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:20:34 by elombard          #+#    #+#             */
/*   Updated: 2023/12/09 02:54:56 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int			args_counter(char **args);
int			check_long_long(char *str_to_check);
long long	ft_atoll(const char *str);

// env.c
int			env_builtin(t_shell *shell);
int			env_parse(char *arg);
char		*env_get_var_name(char *arg);

// exit.c
int			ms_exit_builtin(t_shell *shell, char **command_with_args);
int			ch_exit_builtin(t_shell *shell, char **command_with_args);

// pwd.c
int			pwd_builtin(void);

// export.c
int			is_valid_env_var_name(const char *str);
int			export_sub_print(char **sorted_env, int i, int j, int equal_quote);
void		export_sub_builtin(t_shell *shell, char **command_with_args, int i);
void		export_print(t_shell *shell);
int			export_builtin(t_shell *shell, char **command_with_args);
int			export_parse(char *arg);
int			export_env_alr_exist(char *env_name, char *new_env_name);
char		**env_recreate_newline(char **input, char *new_arg);
void		export_append(t_shell *shell, char *arg);
void		export_replace_at(t_shell *shell, char *arg, int line);
char		**sort_env(char **env);
void		free_env(char **env);

// echo.c
int			echo_builtin(t_shell *shell, char **command_with_args);
void		echo_sub(char **args, int skip_nl);
int			check_tiret_n(char *arg);
int			is_flag_present(char *arg);

// unset.c
char		**unset_delete_arg(char **input, char *new_arg);
int			unset_builtin(t_shell *shell, char **command_with_args);

// cd builtin's functions
char		*cd_strjoin(char *s1, const char *s2);
int			cd_builtin(t_shell *shell, char **path);
int			cd_list_len(t_cd *cd);
void		cd_add_node(t_cd *cd, char *data);
void		cd_remove_last_node(t_cd	*cd);
void		cd_split_path_into_node(t_cd *cd);
void		cd_split_path_into_instructions(t_cd *cd, char *data);
void		cd_cas_default(t_shell *shell, char *data);
void		cd_cas_home(t_shell *shell);
void		cd_cas_stay(t_shell *shell, char *data);
void		cd_cas_absolu(t_shell *shell);
void		cd_cas_tiret(t_shell *shell);
void		cd_cas_back(t_shell *shell);
void		end_of_processing(t_shell *shell, t_cd *instructions);

#endif
