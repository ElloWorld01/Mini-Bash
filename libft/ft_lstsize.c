/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:45:05 by elombard          #+#    #+#             */
/*   Updated: 2022/11/25 17:20:00 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		nb;

	nb = 0;
	if (!lst)
		return (nb);
	p = lst;
	while (p->next)
	{
		p = p->next;
		nb++;
	}
	return (nb + 1);
}
