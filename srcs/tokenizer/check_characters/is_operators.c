/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:54:48 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:36:23 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	is_pipe(char to_find)
{
	return (to_find == '|');
}

static int	is_input_redirection(char to_find)
{
	return (to_find == '<');
}

static int	is_output_redirection(char to_find)
{
	return (to_find == '>');
}

int	is_normal_operator(char to_find)
{
	return (is_pipe(to_find) || is_input_redirection(to_find)
		|| is_output_redirection(to_find));
}
