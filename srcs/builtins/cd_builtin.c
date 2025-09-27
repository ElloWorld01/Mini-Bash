/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:05:48 by elombard          #+#    #+#             */
/*   Updated: 2023/12/01 18:44:55 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	cd_refresh_env(t_shell *shell, char *var_name, char *pwd)
{
	char	**pwd_env;

	pwd_env = malloc(sizeof(char *) * 3);
	if (!pwd_env)
		return ;
	pwd_env[0] = ft_strdup("cd");
	pwd_env[1] = ft_strjoin(var_name, pwd);
	pwd_env[2] = NULL;
	export_builtin(shell, pwd_env);
	free (pwd_env[0]);
	free (pwd_env[1]);
	free (pwd_env[2]);
	pwd_env[0] = NULL;
	pwd_env[1] = NULL;
	pwd_env[2] = NULL;
	free (pwd_env);
	pwd_env = NULL;
	free (pwd);
	pwd = NULL;
	free (var_name);
	var_name = NULL;
	return ;
}

static void	cd_choose_cases(t_shell *shell, char *data)
{
	if (shell->exec->exec_list->command_with_args[1] != NULL)
		if (shell->exec->exec_list->command_with_args[1][0] == '/')
			shell->absolu = 1;
	if (shell->absolu == 0)
	{
		if ((!shell->exec->exec_list->command_with_args[1]))
			cd_cas_home(shell);
		else if (data && ft_strcmp(data, "~") == 0 && shell->cd_index == 1)
			cd_cas_home(shell);
		else if (data && ft_strcmp(data, ".") == 0)
			cd_cas_stay(shell, data);
		else if (data && ft_strcmp(data, "-") == 0)
			cd_cas_tiret(shell);
		else if (data && ft_strcmp(data, "..") == 0)
			cd_cas_back(shell);
		else if (data && data[0] != '\0')
			cd_cas_default(shell, data);
		else
			return ;
	}
	else if (shell->absolu == 1)
		cd_cas_absolu(shell);
}

static t_cd	*cd_sub_builtin(t_shell *shell, char **path)
{
	t_cd	*instructions;

	instructions = ms_calloc(1, sizeof(t_cd), shell);
	instructions->data = NULL;
	instructions->prev = NULL;
	instructions->next = NULL;
	cd_split_path_into_instructions(instructions, path[1]);
	return (instructions);
}

static void	cd_builtin_do_instr(t_shell *shell, t_cd *instructions)
{
	while (instructions && shell->exit_status == -1)
	{
		if (shell->absolu == 0)
			cd_choose_cases(shell, instructions->data);
		shell->cd_index++;
		instructions = instructions->next;
	}
}

int	cd_builtin(t_shell *shell, char **path)
{
	t_cd	*instructions;
	t_cd	*temp;
	char	*pwd;

	if (args_counter(path) > 2)
	{
		printerr("❌ " YELLOW NAME_LOWER ": cd: ");
		printerr(RED "too many arguments" RESET"\n");
		return (shell->exit_status = 1);
	}
	shell->exit_status = -1;
	pwd = getcwd(NULL, 0);
	if (pwd)
		cd_refresh_env(shell, ft_strdup("OLDPWD="), pwd);
	instructions = cd_sub_builtin(shell, path);
	temp = instructions;
	shell->cd_instruction_len = cd_list_len(instructions);
	cd_builtin_do_instr(shell, instructions);
	pwd = getcwd(NULL, 0);
	if (pwd)
		cd_refresh_env(shell, ft_strdup("PWD="), pwd);
	end_of_processing(shell, temp);
	if (shell->exit_status == -1)
		shell->exit_status = 0;
	return (shell->exit_status);
}
