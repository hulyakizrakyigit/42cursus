/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:04:21 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/04 21:57:05 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_itoa(int pid)
{
	char	c;

	if (pid >= 10)
		ft_itoa(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

int	get_client_pid(char *j, int c)
{
	static unsigned int	pid_client;
	static unsigned int	client_pid;

	if (*j <= 31)
	{
		pid_client += c << *j;
		if (*j == 31)
		{
			client_pid = pid_client;
			pid_client = 0;
			(*j)++;
			return (client_pid);
		}
		(*j)++;
	}
	return (0);
}

void	bitoa(int d)
{
	static unsigned char	writer;
	static int				i = 7;
	static char				j;
	static int				client_pid;

	if (j <= 31)
	{
		client_pid = get_client_pid(&j, d);
		return ;
	}
	writer += d << i;
	if (i == 0)
	{
		i = 7;
		if ((char)writer != '\0')
			write(1, &writer, 1);
		else
		{
			j = 0;
			kill(client_pid, SIGUSR2);
		}
		writer = 0;
	}
	else
		i--;
}

void	take(int signal)
{
	if (signal == SIGUSR1)
		bitoa(1);
	else if (signal == SIGUSR2)
		bitoa(0);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = take;
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	write(1, "pid : ", 6);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
