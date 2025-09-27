/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_stop_signal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:36:23 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 20:38:52 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	g_heredoc_stop_signal = 0;

void	heredoc_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_heredoc_stop_signal = SIGINT;
		exit(CHILD_HEREDOC_INTERRUPT);
	}
}

int	heredoc_stop_signal(void)
{
	return (g_heredoc_stop_signal != 0);
}

void	heredoc_stop_signal_reset(void)
{
	g_heredoc_stop_signal = 0;
}
