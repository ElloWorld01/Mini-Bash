/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:48:18 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:48:18 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	ms_handle_error(t_shell *shell, t_error_type error_type)
{
	handle_error(shell, error_type);
	ms_exit(shell, shell->exit_status, TRUE);
}

void	ms_exit(t_shell *shell, int code, int bool_print_exit)
{
	if (bool_print_exit)
		printerr_ln("exit");
	exit_process(shell, code);
}
