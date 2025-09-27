/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type_from_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:24:39 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 20:04:03 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	get_token_type_from_string(char *token, t_shell *shell)
{
	if (shell->tokenizer->is_operator == FALSE)
		return (TOKEN_WORD);
	else if (ft_strcmp(token, "|") == 0)
		return (TOKEN_PIPE);
	else if (ft_strcmp(token, "<") == 0)
		return (TOKEN_INPUT_REDIRECT);
	else if (ft_strcmp(token, ">") == 0)
		return (TOKEN_OUTPUT_REDIRECT);
	else if (ft_strcmp(token, "<<") == 0)
		return (TOKEN_HEREDOC_REDIRECT);
	else if (ft_strcmp(token, ">>") == 0)
		return (TOKEN_APPEND_REDIRECT);
	else
		return (TOKEN_WORD);
}
