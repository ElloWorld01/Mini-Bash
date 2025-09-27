/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:57:41 by elombard          #+#    #+#             */
/*   Updated: 2023/10/05 10:41:14 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

char	*ms_strndup(const char *src, size_t n, t_shell *shell)
{
	char	*copy;

	if (src == NULL)
		return (NULL);
	copy = ms_malloc(sizeof(char) * (n + 1), shell);
	ft_strlcpy(copy, src, n + 1);
	return (copy);
}

char	*ch_strndup(const char *src, size_t n, t_shell *shell)
{
	char	*copy;

	if (src == NULL)
		return (NULL);
	copy = ch_malloc(sizeof(char) * (n + 1), shell);
	ft_strlcpy(copy, src, n + 1);
	return (copy);
}
