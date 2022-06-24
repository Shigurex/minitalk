/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:04:22 by yahokari          #+#    #+#             */
/*   Updated: 2022/06/24 18:07:38 by yahokari         ###   ########.fr       */
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

static void	receive_signal(int signal)
{
	(void)signal;
	ft_putstr_fd("message successfully sent\n", 1);
	exit(0);
}

static void	send_byte(pid_t server_pid, unsigned char byte)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (kill(server_pid, (byte >> (7 - i) & 1) + SIGUSR1))
			exit_safe("failed in kill process\n");
		usleep(60);
		i++;
	}
}

static void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_byte(server_pid, *str);
		str++;
	}
	send_byte(server_pid, *str);
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	sa.sa_handler = &receive_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &sa, NULL))
		exit_safe("failed to receive signal\n");
	send_string(server_pid, argv[2]);
	send_byte(server_pid, EOT);
	while (1)
		pause();
	return (0);
}
