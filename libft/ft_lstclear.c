/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:58:58 by elombard          #+#    #+#             */
/*   Updated: 2022/11/25 18:58:34 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*next;

	if (!lst || !del)
		return ;
	p = lst[0];
	while (p)
	{
		del(p->content);
		next = p->next;
		free(p);
		p = next;
	}
	lst[0] = 0;
}
