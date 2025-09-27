/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:32:09 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:05:58 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	*ms_calloc(size_t count, size_t size, t_shell *shell)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		ms_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (ptr);
}

void	*ch_calloc(size_t count, size_t size, t_shell *shell)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (ptr);
}
