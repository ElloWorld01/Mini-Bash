/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:06:24 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:39:26 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

// TODO enhance error messages
void	handle_error(t_shell *shell, t_error_type error_type)
{
	shell->exit_status = error_type;
	if (error_type == CODE_127_NO_PRESENT)
		printerr_ln(": command not found");
	else if (error_type == MEMORY_ALLOCATION_ERROR)
		printerr_ln("memory error: unable to assign memory");
	else if (error_type == SYNTAX_ERROR_QUOTATION)
		printerr_ln("syntax error: unable to locate closing quotation");
}
