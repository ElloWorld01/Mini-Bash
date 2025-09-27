/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:59:01 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 20:04:18 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

// is_quotes_error.c
int				are_quotes(char to_find);
int				is_quotes_error(char *str);
int				check_amount_char(char *str, char *to_find);
char			*replace_or_remove_word_if_no_substitute(
					t_alter_word *alter_word, t_shell *shell, int *str_iter);

// tokenize_line.c
char			*get_env_var(char *word, t_shell *shell);
int				found_env_var_with_word(char *const *env,
					const char *word_plus_equal);
char			*get_value_of_env_word_key(const char *word, char *const *env);

// list_tokenizer.c
void			push_node(t_token_list **node, char *token, t_token_type type,
					t_shell *shell);
void			free_list(t_token_list **node);

// normal_mode.c
char			*get_normal_operator(const char *line, size_t *str_iter,
					t_shell *shell);

// quotes_operations.c
int				get_count_quotes_in_pairs(const char *line);
char			*check_quotes_and_append_char(char *word, char *token);
char			*remove_quotes_from_word(char *word, t_shell *shell);
int				change_quote_pair(char *quote, const char *word, int word_iter);
char			handle_quote_pair(char quote, char c);

// operators.c
int				is_normal_operator(char to_find);

// tokenization.c
void			tokenize(t_token_list **head, char *token, t_shell *shell);
int				get_token_type_from_string(char *token, t_shell *shell);
void			handle_token(t_token_list **head, char *token, t_shell *shell);
char			*get_token(t_shell *shell, char *line, size_t *str_iter);

// word_handling.c
int				get_word_length_until_delimiters(char *line, char *delimiters,
					size_t *str_iter);
char			*get_word_until_delimiters(char *line, char *delimiters,
					size_t *str_iter, t_shell *shell);
char			*replace_word(t_alter_word *alter_word, t_shell *shell);
char			*remove_word(t_alter_word *alter_word, t_shell *shell,
					int *str_iter);
char			*get_word_expanded(t_shell *shell, char *line,
					size_t *str_iter);

// tokenize_line.c
void			do_tokenize(t_shell *shell);

// line_fonctions.c
void			process_line(t_shell *shell, t_token_list **head,
					size_t line_len);
void			get_command_line(t_shell *shell);

// get_word_after_dollar.c
char			*get_word_after_dollar(size_t iter, char *word_to_expand,
					t_shell *shell);

char			*get_word_until_condition(char *line,
					int condition_stop(char char_to_check,
						size_t char_position_in_word),
					size_t *str_iter, t_shell *shell);
int				get_word_length_until_condition(char *line_after_dollar,
					int condition_stop(char char_to_check,
						size_t char_position_in_word),
					size_t *str_iter);
int				is_env_name_char_allowed(char c);
char			*expansion(char *word_to_expand, int *str_iter, t_shell *shell);
char			*expand_variables_if_any(char *string, t_shell *shell);
void			adjust_str_iter_if_end_of_string(int *str_iter,
					const char *word);
char			*expand_exit_status(char *word_with_quotes,
					int *str_iter, t_shell *shell);
#endif
