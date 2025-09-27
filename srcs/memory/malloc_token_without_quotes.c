/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_token_without_quotes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 05:27:12 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:23:32 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	*malloc_token_without_quotes(char *word, t_shell *shell)
{
	void	*p;

	p = ms_malloc(sizeof(char) * (ft_strlen(word)
				- get_count_quotes_in_pairs(word) + 1), shell);
	return (p);
}
