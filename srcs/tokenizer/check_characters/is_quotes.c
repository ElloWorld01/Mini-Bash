/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:14:46 by elombard          #+#    #+#             */
/*   Updated: 2023/10/10 03:07:41 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

int	is_single_quote(char to_find)
{
	return (to_find == '\'');
}

int	is_double_quote(char to_find)
{
	return (to_find == '\"');
}

int	are_quotes(char to_find)
{
	return (is_single_quote(to_find) || is_double_quote(to_find));
}
