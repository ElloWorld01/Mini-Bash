/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_correct_return_code.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:08:57 by elombard          #+#    #+#             */
/*   Updated: 2023/12/03 17:23:44 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minibash.h"

static int	handle_common_signal(int signal_code)
{
	if (signal_code == SIGHUP)
		printerr_ln("Hangup");
	else if (signal_code == SIGINT)
		printerr_ln("Interrupt");
	else if (signal_code == SIGQUIT)
		printerr_ln("Quit");
	else if (signal_code == SIGILL)
		printerr_ln("Illegal instruction");
	else if (signal_code == SIGTRAP)
		printerr_ln("BPT trace/trap");
	else if (signal_code == SIGABRT)
		printerr_ln("ABORT instruction");
	else if (signal_code == SIGFPE)
		printerr_ln("Floating point exception");
	else if (signal_code == SIGKILL)
		printerr_ln("Killed");
	else if (signal_code == SIGBUS)
		printerr_ln("Bus error");
	else if (signal_code == SIGSEGV)
		printerr_ln("Segmentation fault");
	else
		return (FALSE);
	return (TRUE);
}

static int	handle_uncommon_signal(int signal_code)
{
	if (signal_code == SIGSYS)
		printerr_ln("Bad system call");
	else if (signal_code == SIGPIPE)
		printerr_ln("Broken pipe");
	else if (signal_code == SIGALRM)
		printerr_ln("Alarm clock");
	else if (signal_code == SIGTERM)
		printerr_ln("Terminated");
	else if (signal_code == SIGURG)
		printerr_ln("Urgent IO condition");
	else if (signal_code == SIGSTOP)
		printerr_ln("Stopped (signal)");
	else if (signal_code == SIGTSTP)
		printerr_ln("Stopped");
	else if (signal_code == SIGCONT)
		printerr_ln("Continued");
	else if (signal_code == SIGCHLD)
		printerr_ln("Child death or stop");
	else
		return (FALSE);
	return (TRUE);
}

static int	handle_rare_signal(int signal_code)
{
	if (signal_code == SIGTTIN)
		printerr_ln("Stopped (tty input)");
	else if (signal_code == SIGTTOU)
		printerr_ln("Stopped (tty output)");
	else if (signal_code == SIGIO)
		printerr_ln("I/O ready");
	else if (signal_code == SIGXCPU)
		printerr_ln("CPU limit");
	else if (signal_code == SIGXFSZ)
		printerr_ln("File limit");
	else if (signal_code == SIGVTALRM)
		printerr_ln("Alarm (virtual)");
	else if (signal_code == SIGPROF)
		printerr_ln("Alarm (profile)");
	else if (signal_code == SIGWINCH)
		printerr_ln("Window changed");
	else if (signal_code == SIGUSR1)
		printerr_ln("User signal 1");
	else if (signal_code == SIGUSR2)
		printerr_ln("User signal 2");
	else if (signal_code == SIGPWR)
		printerr_ln("power failure imminent");
	else
		return (FALSE);
	return (TRUE);
}

static void	print_signal_error(int signal_code)
{
	if (handle_common_signal(signal_code) == TRUE)
		return ;
	if (handle_uncommon_signal(signal_code) == TRUE)
		return ;
	if (handle_rare_signal(signal_code) == TRUE)
		return ;
}

int	get_correct_return_code(int return_code)
{
	if (WIFEXITED(return_code))
		return_code = WEXITSTATUS(return_code);
	else if (WIFSIGNALED(return_code))
	{
		print_signal_error(return_code);
		return_code = WTERMSIG(return_code) + 128;
	}
	return (return_code);
}
