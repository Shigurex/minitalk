/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:32:35 by yahokari          #+#    #+#             */
/*   Updated: 2022/07/01 00:49:07 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdio.h>
#include	<signal.h>
#include	<sys/types.h>
#include	"libft/libft.h"

#define EOT 4

static void	exit_safe(char *message)
{
	ft_putstr_fd(message, 1);
	exit(1);
}

static void	send_acknowledge(pid_t client_pid)
{
	if (kill(client_pid, SIGUSR1))
		exit_safe("failed in kill process\n");
}

static void	receive_signal(int signal, siginfo_t *siginfo, void *text)
{
	static int				i;
	static unsigned char	c;

	(void)text;
	if (signal == SIGUSR2)
		c |= 1 << (7 - i);
	i++;
	if (i == 8)
	{
		if (c == EOT)
			send_acknowledge(siginfo->si_pid);
		else if (c != '\0')
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_sigaction = &receive_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exit_safe("failed to receive signal\n");
	while (1)
		pause();
	return (0);
}
