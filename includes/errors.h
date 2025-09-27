/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:19:37 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 18:46:59 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

void	ms_handle_error(t_shell *shell, t_error_type error_type);
void	ch_handle_error(t_shell *shell, t_error_type error_type);

void	printerr_shell(char *message);
void	printerr_shell_ln(char *message);
void	printerr_src_msg_ln(char *source, char *message);
void	print_error_syntax_char(char char_near);
void	printerr_syntax_str(char *char_near);
void	printerr_no_color(char *message);
void	printerr(char *message);
void	printerr_ln(char *message);

void	printerr_heredoc_eof(char *stop_word);
char	*printerr_infile(char *filename);
char	*printerr_outfile(char *filename);

void	handle_error(t_shell *shell, t_error_type error_type);

void	ms_exit(t_shell *shell, int code, int bool_print_exit);
void	ch_exit(t_shell *shell, int code);

void	exit_process(t_shell *shell, int code);

#endif
