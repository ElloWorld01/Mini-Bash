/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:47:42 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:47:53 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	ch_handle_error(t_shell *shell, t_error_type error_type)
{
	handle_error(shell, error_type);
	ch_exit(shell, shell->exit_status);
}

void	ch_exit(t_shell *shell, int code)
{
	exit_process(shell, code);
}
