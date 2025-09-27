/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:20:31 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:44:01 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:37:41 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:16:37 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	printerr_no_color(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
}

void	printerr_src_msg_ln(char *source, char *message)
{
	printerr_shell(source);
	printerr_no_color(RED);
	printerr_no_color(": ");
	printerr_no_color(message);
	printerr_no_color("\n");
	printerr_no_color(RESET);
}

void	printerr(char *message)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
}

void	printerr_ln(char *message)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
}
