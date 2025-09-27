/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_execute_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:29:47 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 17:30:16 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	sigint_execute_file(int sig)
{
	if (sig == SIGINT)
	{
		exit(CODE_130_INTERRUPT);
	}
}
