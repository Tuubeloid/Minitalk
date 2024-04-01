/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <Tvalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:30:01 by tvalimak          #+#    #+#             */
/*   Updated: 2024/02/27 11:15:02 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(int pid, char c, int i)
{
	if (kill(pid, 0) == -1)
	{
		ft_printf("[+] Error: \033[31mThis PID doesn't exist\n\033[0m");
		exit(EXIT_FAILURE);
	}
	if (i < 8)
	{
		if ((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		ft_sender(pid, c, i + 1);
	}
}

void	ft_handler2(int pid)
{
	if (pid == SIGUSR1)
	{
		ft_printf("[+] Server: \033[32mMessage received\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid_server;

	i = 0;
	if (ac == 3)
	{
		signal(SIGUSR1, ft_handler2);
		signal(SIGUSR2, ft_handler2);
		pid_server = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_sender(pid_server, av[2][i], 0);
			i++;
		}
		ft_sender(pid_server, '\0', 0);
		while (42)
			pause();
	}
	else
	{
		ft_printf("usage: ./client <server's pid> <string>\n");
		return (1);
	}
	return (0);
}
