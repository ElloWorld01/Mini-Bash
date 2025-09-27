/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:45:07 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/01 18:47:07 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	cd_sub_cas_tiret(t_shell *shell, t_cd *temp, char *pwd)
{
	if (shell->tiret == 1)
	{
		chdir(temp->data);
		printf(GREEN "🔙 %s\n" RESET, temp->data);
		shell->tiret = 0;
	}
	else if (shell->tiret == 0)
	{
		chdir(temp->prev->data);
		printf(GREEN "🔙 %s\n" RESET, temp->prev->data);
		shell->tiret = 1;
	}
	free (pwd);
}

void	cd_cas_tiret(t_shell *shell)
{
	t_cd	*temp;
	char	*pwd;

	temp = shell->cd_tiret;
	if (cd_list_len(temp) <= 1)
	{
		printf("❌ cd: OLDPWD not set\n");
		shell->exit_status = 1;
		return ;
	}
	pwd = getcwd(NULL, 0);
	while (temp->next)
		temp = temp->next;
	cd_sub_cas_tiret(shell, temp, pwd);
}

static char	*cd_sub_cas_back(t_cd *temp)
{
	char	*absolute_path;

	absolute_path = ft_strdup("");
	while (temp)
	{
		if (ft_strcmp(temp->data, "/") == 0)
			temp = temp->next;
		else
		{
			absolute_path = cd_strjoin(absolute_path, "/");
			absolute_path = cd_strjoin(absolute_path, temp->data);
			temp = temp->next;
		}
	}
	return (absolute_path);
}

void	cd_cas_back(t_shell *shell)
{
	char	*absolute_path;
	t_cd	*temp;
	char	*pwd;

	temp = shell->cd_split_path;
	pwd = getcwd(NULL, 0);
	if ((pwd && ft_strcmp(pwd, "/") == 0)
		|| cd_list_len(shell->cd_split_path) <= 2)
	{
		chdir("/");
		if (shell->cd_instruction_len == shell->cd_index + 1)
			cd_add_node(shell->cd_tiret, pwd);
		free (pwd);
		return ;
	}
	free (pwd);
	cd_remove_last_node(shell->cd_split_path);
	absolute_path = cd_sub_cas_back(temp);
	if (chdir(absolute_path) == -1)
		printerr(RED "❌ cd: error retrieving directory\n" RESET);
	pwd = getcwd(NULL, 0);
	if (shell->cd_instruction_len == shell->cd_index + 1)
		cd_add_node(shell->cd_tiret, absolute_path);
	free (pwd);
	free (absolute_path);
}

void	end_of_processing(t_shell *shell, t_cd *instructions)
{
	shell->absolu = 0;
	shell->cd_index = 0;
	free_cd_list(instructions);
}
