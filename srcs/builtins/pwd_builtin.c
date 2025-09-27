/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:18:45 by elombard          #+#    #+#             */
/*   Updated: 2023/12/12 18:15:17 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minibash.h"

int	pwd_builtin(void)
{
	char	*value_of_pwd;

	value_of_pwd = getcwd(NULL, 0);
	if (value_of_pwd == NULL)
	{
		printerr("❌ " YELLOW NAME_LOWER);
		printerr("cd: error retrieving current directory\n" RESET);
		return (CMD_FAILURE);
	}
	printf("%s\n", value_of_pwd);
	free (value_of_pwd);
	return (CMD_SUCCESS);
}
