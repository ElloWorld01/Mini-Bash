/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:38:52 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/01 18:44:00 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

void	cd_add_node(t_cd *cd, char *data)
{
	t_cd	*temp;
	t_cd	*new;

	temp = cd;
	new = ft_calloc(1, sizeof(t_cd));
	new->data = ft_strdup(data);
	new->next = NULL;
	new->prev = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	cd_remove_last_node(t_cd *cd)
{
	t_cd	*temp;

	temp = cd;
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->prev)
		temp->prev->next = NULL;
	free(temp->data);
	temp->data = NULL;
	free(temp);
}

void	cd_split_path_into_node(t_cd *cd)
{
	char	**to_process;
	char	*pwd;
	int		i;

	i = -1;
	pwd = getcwd(NULL, 0);
	to_process = ft_split(pwd, '/');
	free(pwd);
	free(cd->data);
	cd->data = ft_strdup("/");
	while (to_process[++i] != NULL)
	{
		cd_add_node(cd, to_process[i]);
		free (to_process[i]);
	}
	free(to_process);
}

void	cd_split_path_into_instructions(t_cd *cd, char *data)
{
	char	**to_process;
	int		i;

	if (!data)
	{
		cd->data = ft_strdup("\0");
		cd->next = NULL;
		cd->prev = NULL;
		return ;
	}
	if (ft_strcmp(data, "/") == 0)
	{
		cd_add_node(cd, "\0");
		return ;
	}
	i = -1;
	to_process = ft_split(data, '/');
	while (to_process[++i] != NULL)
		cd_add_node(cd, to_process[i]);
	free_char_array(to_process);
}
