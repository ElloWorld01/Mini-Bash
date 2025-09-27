/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaling.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:39:50 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 20:39:30 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALING_H
# define SIGNALING_H

void	heredoc_signal_handler(int sig);
int		heredoc_stop_signal(void);
void	heredoc_stop_signal_reset(void);

void	init_signals(void);
void	sigint_newline(int sig);
void	sigint_newline_redisplay(int sig);
void	sigquit_newline(int sig);

#endif
