/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:59:49 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:02 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checked(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		p += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		p += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		p += ft_putstr("0x");
		p += ft_pointer(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		p += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (p);
}

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

static void	process_str(const char *str, va_list arg, int *check)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(str);
	while (i < k)
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			(*check)++;
		}
		if (str[i] == '%')
		{
			i++;
			if (str[i] == ' ')
				(*check) += write(1, " ", 1);
			while (str[i] == ' ' && str[i])
				i++;
			(*check) += ft_checked(str[i], arg);
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		check;
	va_list	arg;

	check = 0;
	va_start(arg, str);
	process_str(str, arg, &check);
	va_end(arg);
	return (check);
}
