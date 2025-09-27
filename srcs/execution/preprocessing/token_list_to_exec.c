/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:55:02 by elombard          #+#    #+#             */
/*   Updated: 2023/11/27 15:39:50 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

void	get_current_command(t_shell *shell, t_token_list *token_list,
							t_exec_list *exec_list)
{
	char	**current_command;
	int		command_words;
	int		word_iter;

	command_words = number_of_command_words(token_list);
	current_command = ms_malloc(sizeof(char *) * (command_words + 1), shell);
	word_iter = 0;
	while (word_iter < command_words && token_list)
	{
		if (token_list->type == TOKEN_WORD)
		{
			current_command[word_iter] = ft_strdup(token_list->value);
			++word_iter;
		}
		token_list = token_list->next;
	}
	current_command[word_iter] = NULL;
	exec_list->command_with_args = current_command;
}

t_exec_list	*init_exec_list_type(void)
{
	t_exec_list	*exec_list;

	exec_list = ft_calloc(1, sizeof(t_exec_list));
	exec_list->heredoc_read_fd = PARENT_HEREDOC_NOT_PRESENT;
	exec_list->command_is_present = FALSE;
	exec_list->in_redirections = NULL;
	exec_list->out_redirections = NULL;
	exec_list->next = NULL;
	return (exec_list);
}

void	exec_list_init(t_shell *shell, t_token_list *token_list)
{
	int	commands_count;

	commands_count = number_of_commands(token_list);
	shell->exec->commands_count = malloc(sizeof(int));
	*shell->exec->commands_count = commands_count;
}

void	token_list_to_exec(t_shell *shell)
{
	t_token_list		*token_list;
	t_exec_list			*exec_list;
	t_list_redirections	*current_in_redirections;
	t_list_redirections	*current_out_redirections;

	token_list = shell->tokenizer->head;
	exec_list_init(shell, token_list);
	exec_list = init_exec_list_type();
	shell->exec->exec_list = exec_list;
	current_in_redirections = NULL;
	current_out_redirections = NULL;
	while (token_list)
	{
		loop_until_word(&current_in_redirections, &current_out_redirections,
			&token_list, &exec_list);
		if (token_list == NULL)
			break ;
		if (exec_list->command_is_present == FALSE)
		{
			get_current_command(shell, token_list, exec_list);
			exec_list->command_is_present = TRUE;
		}
		token_list = token_list->next;
	}
}
