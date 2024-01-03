/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:50:33 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/05 14:18:28 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
void	ft_itoa(int pid);
int		ft_atoi(char *str);
void	atobit(int c, int pid);
void	take(int sig);
int		get_client_pid(char *j, int c);
void	bitoa(int d);
int		ft_isdigit(int c);
void	push_client_pid(int server_pid);
void	is_arrive(int a);

#endif
