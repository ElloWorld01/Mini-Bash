/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:47:19 by ldalmass          #+#    #+#             */
/*   Updated: 2023/12/01 18:43:28 by ldalmass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

static void	cd_sub_cas_absolu(t_shell *shell)
{
	t_cd	*temp;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	cd_add_node(shell->cd_tiret, pwd);
	free (pwd);
	temp = shell->cd_split_path;
	while (cd_list_len(temp) > 1)
		cd_remove_last_node(temp);
}

void	cd_cas_absolu(t_shell *shell)
{
	int		i;
	char	*path;
	char	**divided_path;

	path = ft_strdup(shell->exec->exec_list->command_with_args[1]);
	if (chdir(path) == -1)
	{
		printerr("❌ " YELLOW NAME_LOWER " : cd: ");
		printerr(path);
		printerr(": " RED MSG_NO_SUCH_FILE_OR_DIR RESET "\n");
		free (path);
		shell->exit_status = 1;
		return ;
	}
	cd_sub_cas_absolu(shell);
	divided_path = ft_split(path, '/');
	i = -1;
	while (divided_path[++i] != NULL)
	{
		cd_add_node(shell->cd_split_path, divided_path[i]);
		free (divided_path[i]);
	}
	shell->tiret = 0;
	free (divided_path);
	free (path);
}

int	cd_list_len(t_cd *cd)
{
	t_cd	*temp;
	int		i;

	i = 0;
	temp = cd;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

char	*cd_strjoin(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}
