/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:56:40 by elombard          #+#    #+#             */
/*   Updated: 2023/10/13 23:58:15 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static void	get_redirection_left(const char *line, size_t *str_iter,
									char **operator, t_shell *shell)
{
	if (line[*str_iter + 1] == '<')
	{
		*operator = ms_strdup(shell, "<<");
		*str_iter += 1;
	}
	else
		*operator = ms_strdup(shell, "<");
}

static void	get_redirection_right(const char *line, size_t *str_iter,
									char **operator, t_shell *shell)
{
	if (line[*str_iter + 1] == '>')
	{
		*operator = ms_strdup(shell, ">>");
		*str_iter += 1;
	}
	else
		*operator = ms_strdup(shell, ">");
}

char	*get_normal_operator(const char *line, size_t *str_iter, t_shell *shell)
{
	char	*operator;

	operator = NULL;
	shell->tokenizer->is_operator = TRUE;
	if (line[*str_iter] == '|')
		operator = ms_strdup(shell, "|");
	else if (line[*str_iter] == '<')
		get_redirection_left(line, str_iter, &operator, shell);
	else if (line[*str_iter] == '>')
		get_redirection_right(line, str_iter, &operator, shell);
	*str_iter += 1;
	return (operator);
}
