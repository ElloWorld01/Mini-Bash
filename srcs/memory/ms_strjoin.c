/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 04:59:16 by elombard          #+#    #+#             */
/*   Updated: 2023/11/24 17:12:25 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

char	*ms_strjoin(char const *s1, char const *s2, t_shell *shell)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result == NULL)
		ms_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (result);
}

char	*ch_strjoin(char const *s1, char const *s2, t_shell *shell)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result == NULL)
		ch_handle_error(shell, MEMORY_ALLOCATION_ERROR);
	return (result);
}
