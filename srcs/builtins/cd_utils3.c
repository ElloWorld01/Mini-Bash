/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:14:58 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/01 18:42:35 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	cd_sub_cas_home(t_shell *shell)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (shell->cd_instruction_len == shell->cd_index + 1)
		cd_add_node(shell->cd_tiret, pwd);
	free (pwd);
	shell->tiret = 0;
}

void	cd_cas_home(t_shell *shell)
{
	t_cd	*temp;
	char	*homie;

	temp = shell->cd_split_path;
	while (cd_list_len(temp) != 1)
		cd_remove_last_node(temp);
	homie = expand_variables_if_any(ft_strdup("$HOME"), shell);
	if (chdir(homie) == -1)
	{
		printerr("❌ cd: HOME not set\n");
		free (homie);
		shell->exit_status = 1;
		return ;
	}
	free (homie);
	homie = NULL;
	homie = expand_variables_if_any(ft_strdup("$USER"), shell);
	cd_add_node(shell->cd_split_path, "home");
	cd_add_node(shell->cd_split_path, homie);
	free (homie);
	cd_sub_cas_home(shell);
}

void	cd_cas_default(t_shell *shell, char *data)
{
	char	*pwd;

	if (chdir(data) == -1)
	{
		printerr("❌ " YELLOW NAME_LOWER " : cd: ");
		printerr(data);
		printerr(" : " RED MSG_NO_SUCH_FILE_OR_DIR RESET "\n");
		shell->exit_status = 1;
		return ;
	}
	cd_add_node(shell->cd_split_path, data);
	pwd = getcwd(NULL, 0);
	if (shell->cd_instruction_len == shell->cd_index + 1)
		cd_add_node(shell->cd_tiret, pwd);
	free (pwd);
	shell->tiret = 0;
}

void	cd_cas_stay(t_shell *shell, char *data)
{
	char	*pwd;

	if (ft_strcmp(shell->exec->exec_list->command_with_args[1], data) != 0)
		return ;
	pwd = getcwd(NULL, 0);
	if (shell->cd_instruction_len == shell->cd_index + 1 && pwd)
		cd_add_node(shell->cd_tiret, pwd);
	shell->tiret = 0;
	free (pwd);
}
