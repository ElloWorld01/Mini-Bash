/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:46:53 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 18:33:12 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	print_error_syntax_char(char char_near)
{
	printerr_shell(SYNTAX_ERROR_NEAR);
	printerr_no_color(RED);
	printerr_no_color("`");
	ft_putchar_fd(char_near, STDERR_FILENO);
	printerr_no_color("'\n");
	printerr_no_color(RESET);
}

void	printerr_syntax_str(char *char_near)
{
	printerr_shell(SYNTAX_ERROR_NEAR);
	printerr_no_color(RED);
	printerr_no_color("`");
	printerr_no_color(char_near);
	printerr_no_color("'\n");
	printerr_no_color(RESET);
}
