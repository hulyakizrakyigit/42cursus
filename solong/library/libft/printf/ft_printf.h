/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:56:44 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/21 16:27:45 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_u(unsigned int u);
int		ft_pointer(unsigned long p);
int		ft_hex(unsigned int x, int b);
int		ft_putchar(char c);
int		ft_putnbr(int nb);

int		ft_printf(const char *str, ...);
#endif
