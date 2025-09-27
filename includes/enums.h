/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:05:21 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 23:52:13 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_token_type
{
	TOKEN_PIPE,
	TOKEN_INPUT_REDIRECT,
	TOKEN_OUTPUT_REDIRECT,
	TOKEN_HEREDOC_REDIRECT,
	TOKEN_APPEND_REDIRECT,
	TOKEN_WORD,
	TOKEN_INFILE,
	TOKEN_HEREDOC_WORD,
	TOKEN_OUTFILE_NORMAL,
	TOKEN_OUTFILE_APPEND,
}	t_token_type;

typedef enum e_error_type
{
	SUCCESS = 0,
	NO_MESSAGE = 1,
	CODE_126_PRESENT_BUT_NOT_EXECUTABLE = 126,
	CODE_127_NO_PRESENT = 127,
	CODE_130_INTERRUPT = 130,
	MEMORY_ALLOCATION_ERROR,
	SYNTAX_ERROR_QUOTATION,
}	t_error_type;

#endif
