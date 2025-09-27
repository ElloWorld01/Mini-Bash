/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_quote_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:56:41 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 18:12:28 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	change_quote_mode(char current_char, char *quote_mode)
{
	if (*quote_mode == '\0')
		*quote_mode = current_char;
	else if (*quote_mode == current_char)
		*quote_mode = '\0';
}
