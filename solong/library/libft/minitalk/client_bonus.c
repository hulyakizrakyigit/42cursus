/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:05:22 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/04 21:56:40 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	atobit(int c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		--i;
	}
}

void	push_client_pid(int server_pid)
{
	int	pid;
	int	i;

	i = 0;
	pid = getpid();
	while (i < 32)
	{
		if (pid & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		pid = pid >> 1;
		i++;
	}
}

void	is_arrive(int a)
{
	(void)a;
	write(1, "Message Sent", 12);
}

int	main(int ac, char **av)
{
	static int	i;
	int			pid;
	char		*str;

	signal(SIGUSR2, is_arrive);
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!ft_strchr("0123456789", av[1][i++]))
				return (1);
		}
		pid = ft_atoi(av[1]);
		push_client_pid(pid);
		str = av[2];
		while (*str)
		{
			atobit(*str, pid);
			str++;
		}
		if (*av[2])
			atobit('\n', pid);
		atobit('\0', pid);
	}
}
