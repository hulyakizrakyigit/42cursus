/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:55:02 by makbulut          #+#    #+#             */
/*   Updated: 2023/12/04 21:48:23 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_itoa(int pid)
{
	char	c;

	if (pid >= 10)
		ft_itoa(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

void	bitoa(int x)
{
	static unsigned char	writer;
	static int				i = 6;

	writer += x << i;
	if (i == 0)
	{
		i = 6;
		write(1, &writer, 1);
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
