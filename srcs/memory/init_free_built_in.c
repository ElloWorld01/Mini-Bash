/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_built_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:17:16 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/01 18:47:25 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	init_cd(t_shell *shell)
{
	shell->cd_tiret = ms_calloc(1, sizeof(t_cd), shell);
	shell->cd_tiret->data = getcwd(NULL, 0);
	shell->cd_tiret->prev = NULL;
	shell->cd_tiret->next = NULL;
	shell->tiret = 0;
	shell->absolu = 0;
	shell->cd_index = 0;
	shell->cd_split_path = ms_calloc(1, sizeof(t_cd), shell);
	shell->cd_split_path->data = NULL;
	shell->cd_split_path->prev = NULL;
	shell->cd_split_path->next = NULL;
	cd_split_path_into_node(shell->cd_split_path);
}

void	free_cd_list(t_cd *list)
{
	t_cd	*temp;

	if (list == NULL)
		return ;
	while (list->prev != NULL)
		list = list->prev;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->data);
		temp->data = NULL;
		free(temp);
		temp = NULL;
	}
}

void	free_cd(t_shell *shell)
{
	free(shell->cd_tiret->data);
	shell->cd_tiret->data = NULL;
	free_cd_list(shell->cd_tiret);
	shell->cd_tiret = NULL;
	free_cd_list(shell->cd_split_path);
	shell->cd_split_path = NULL;
	free(shell->cd_split_path);
}
