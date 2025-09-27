/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:10:17 by elombard          #+#    #+#             */
/*   Updated: 2023/11/29 19:21:49 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	initiate_shell_vars(t_shell *shell)
{
	init_tokenizer(shell);
	init_exec(shell);
	shell->line_readed = NULL;
	shell->line_readed_dup = NULL;
}

void	free_shell_vars(t_shell *shell)
{
	ms_free(shell->line_readed);
	shell->line_readed = NULL;
	ms_free(shell->line_readed_dup);
	shell->line_readed_dup = NULL;
	free_tokenizer(shell);
	free_exec(shell);
}
