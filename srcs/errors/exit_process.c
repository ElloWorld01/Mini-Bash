/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:08:00 by elombard          #+#    #+#             */
/*   Updated: 2023/11/25 16:17:55 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	exit_process(t_shell *shell, int code)
{
	free_cd(shell);
	ms_free(shell->line_history_dup_check);
	shell->line_history_dup_check = NULL;
	free_shell_vars(shell);
	exit(code % 256);
}
