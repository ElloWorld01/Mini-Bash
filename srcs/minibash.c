/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minibash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:31:50 by ncardozo          #+#    #+#             */
/*   Updated: 2023/12/05 13:50:13 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minibash.h"

static char	**env_add_basic_entries(t_shell *shell)
{
	char	**env;
	char	*cwd;

	while (*shell->env)
	{
		free(*shell->env);
		shell->env++;
	}
	free (shell->env);
	env = malloc(sizeof(char *) * 3);
	if (!env)
		return (NULL);
	env[2] = NULL;
	cwd = getcwd(NULL, 0);
	env[0] = ft_strdup("OLDPWD");
	env[1] = ft_strjoin("PWD=", cwd);
	free(cwd);
	return (env);
}

char	**env_super_strdup(char **input)
{
	char	**result;
	int		i;

	i = 0;
	while (input[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = NULL;
	i = -1;
	while (input[++i] != NULL)
		result[i] = ft_strdup(input[i]);
	return (result);
}

void	init_shell_args(int argc, char **argv, char **env, t_shell *shell)
{
	shell->argc = argc;
	shell->argv = argv;
	shell->env = env_super_strdup(env);
	if (!shell->env || !shell->env[0])
		shell->env = env_add_basic_entries(shell);
	shell->exit_status = 0;
	shell->line_history_dup_check = NULL;
}

static void	add_command_to_history(t_shell *shell)
{
	if (is_empty_line(shell->line_readed))
		return ;
	if (shell->line_history_dup_check != NULL)
	{
		if (ft_strcmp(shell->line_history_dup_check, shell->line_readed) != 0)
			add_history(shell->line_readed);
		ms_free(shell->line_history_dup_check);
		shell->line_history_dup_check = NULL;
	}
	else
	{
		add_history(shell->line_readed);
	}
	shell->line_history_dup_check = ft_strdup(shell->line_readed);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	init_shell_args(argc, argv, env, &shell);
	init_cd(&shell);
	while (1)
	{
		initiate_shell_vars(&shell);
		init_signals();
		get_command_line(&shell);
		add_command_to_history(&shell);
		if (do_parsing_line(&shell) == TRUE)
		{
			do_tokenize(&shell);
			do_execution(&shell);
		}
		else
			shell.exit_status = 2;
		free_shell_vars(&shell);
	}
	return (0);
}
