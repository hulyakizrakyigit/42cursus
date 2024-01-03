/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:57:10 by makbulut          #+#    #+#             */
/*   Updated: 2023/12/05 14:18:22 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
void	ft_itoa(int pid);
int		ft_atoi(char *str);
void	atobit(int c, int pid);
void	take(int sig);
void	bitoa(int x);
int		ft_isdigit(int c);

#endif
