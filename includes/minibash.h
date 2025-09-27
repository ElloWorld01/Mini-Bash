/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minibash.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:39:50 by elombard          #+#    #+#             */
/*   Updated: 2023/12/04 15:27:34 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIBASH_H
# define MINIBASH_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "../libft/libft.h"

# include "enums.h"
# include "macros.h"
# include "structs.h"
# include "builtins.h"
# include "errors.h"
# include "execution.h"
# include "tokenizer.h"
# include "memory.h"
# include "parsing.h"
# include "signaling.h"

#endif
