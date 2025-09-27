/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:46:16 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:46:16 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	printerr_shell(char *message)
{
	printerr_no_color("❌ " YELLOW "-" NAME_LOWER ": ");
	printerr_no_color(RED);
	printerr_no_color(message);
	printerr_no_color(RESET);
}

void	printerr_shell_ln(char *message)
{
	printerr_shell(message);
	printerr_no_color("\n");
	printerr_no_color(RESET);
}
