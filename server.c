/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <Tvalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:58:27 by tvalimak          #+#    #+#             */
/*   Updated: 2024/02/27 13:53:42 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*null_return(char c, char *new)
{
	if (!new)
	{
		return (NULL);
	}
	new[0] = c;
	new[1] = '\0';
	return (new);
}

char	*add_c_to_str(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = (char *)malloc(sizeof(char) * 2);
		return (null_return(c, new));
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(str);
	return (new);
}

char	*print_and_free(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	free(str);
	return (NULL);
}

void	action(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static char	*str = NULL;

	(void)context;
	if (signal == SIGUSR1)
		c |= (1 << i);
	if (++i == 8)
	{
		if (c == '\0')
		{
			str = print_and_free(str);
			kill(info->si_pid, SIGUSR1);
		}
		else
			str = add_c_to_str(str, c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: \033[31m%d\033[0m\n", getpid());
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (42)
		pause();
	return (0);
}
