/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalmass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:07:26 by elombard          #+#    #+#             */
/*   Updated: 2023/12/05 16:39:32 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/************* PROMPT **************/
# define PROMPT "\033[1;34mMiniBash\033[0;37m$ \033[0m"
# define NAME_LOWER "minibash"
# define NAME_DOTS "minibash: "

/************* BOOLEANS **************/
# define TRUE 1
# define FALSE 0

/************* ERROR RETURN CODES **************/
# define CMD_SUCCESS 0
# define CMD_FAILURE 1

/************* ERROR MESSAGES **************/
# define SYNTAX_ERROR_NEAR "syntax error near unexpected token "
# define HEREDOC_ERR "warning: here-document delimited by end-of-file (wanted `"
# define MSG_NO_SUCH_FILE_OR_DIR "No such file or directory"
# define MSG_PERM_DENIED "Permission denied"
# define MSG_IS_A_DIR "Is a directory"
# define MSG_RECURSIVE_FILE "Recursive file"
# define MSG_CMD_NOT_FOUND "command not found"

/************* PIPES **************/
# define PIPE_READ 0
# define PIPE_WRITE 1
# define PARENT_HEREDOC_FAIL -1
# define PARENT_HEREDOC_NOT_PRESENT -2
# define PARENT_HEREDOC_INTERRUPT -3
# define CHILD_HEREDOC_INTERRUPT 2

/************* TOKENS **************/
# define DELIMITERS_TOKENS "|<> \t"
# define SHELL_SPACES " \t"

/************* LONG LONG PARSING (exit builtin) **************/
# define LONG_LONG_LEN 19
# define LONG_LONG_LEN_MINUS 20
# define LONG_LONG_MAX_STR "9223372036854775807"
# define LONG_LONG_MIN_STR "9223372036854775808"
# define LONG_LONG_MIN_STR_MINUS "-9223372036854775808"

/************* COLORS **************/
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define BLACK "\033[30m"
# define WHITE "\033[37m"

#endif
