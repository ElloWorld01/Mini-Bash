/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:53:56 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 18:09:39 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		is_empty_line(char *str);
int		do_parsing_line(t_shell *shell);
void	change_quote_mode(char current_char, char *quote_mode);
int		check_is_final_pipe_not_followed_by_expression(char *line);
int		check_consecutive_chars_spaces(const char *line, int limit, char c);
int		check_consecutive_chars(const char *line, int limit, char c);
int		check_after_redirection_if_filename_is_valid(char *line);

#endif
