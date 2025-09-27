/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 04:00:52 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 21:19:52 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

char	*ms_strdup(t_shell *shell, char *src)
{
	char	*copy;

	copy = ft_strdup(src);
	if (copy == NULL)
		ms_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (copy);
}

char	*ch_strdup(char *src, t_shell *shell)
{
	char	*copy;

	copy = ft_strdup(src);
	if (copy == NULL)
		ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (copy);
}
