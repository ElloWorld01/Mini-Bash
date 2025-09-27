/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:18:30 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 21:19:25 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	*malloc_token_without_quotes(char *word, t_shell *shell);
void	*ms_calloc(size_t count, size_t size, t_shell *shell);
void	ms_free(void *ptr);
void	*ms_malloc(size_t size, t_shell *shell);
char	*ms_strdup(t_shell *shell, char *src);
char	*ms_strjoin(char const *s1, char const *s2, t_shell *shell);
char	*ms_strndup(const char *src, size_t n, t_shell *shell);

void	*ch_calloc(size_t count, size_t size, t_shell *shell);
void	*ch_malloc(size_t size, t_shell *shell);
char	*ch_strdup(char *src, t_shell *shell);
char	*ch_strjoin(char const *s1, char const *s2, t_shell *shell);
char	*ch_strndup(const char *src, size_t n, t_shell *shell);

void	initiate_shell_vars(t_shell *shell);
void	free_shell_vars(t_shell *shell);
void	init_alter_word(t_shell *shell, char *string, char *old_word,
			int old_word_position);
void	free_alter_word(t_shell *shell);

void	init_tokenizer(t_shell *shell);
void	free_tokenizer(t_shell *shell);

void	init_exec(t_shell *shell);
void	free_exec(t_shell *shell);

void	init_cd(t_shell *shell);
void	free_cd(t_shell *shell);

void	free_char_array(char **array);
void	free_cd_list(t_cd *list);

#endif
