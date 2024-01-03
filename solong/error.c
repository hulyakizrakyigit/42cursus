/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:40:49 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/10 15:19:17 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "library/libft/libft.h"
#include "so_long.h"

void	exiterr(int err_no, char *err, t_info *info)
{
	dispose(info);
	ft_putstr_fd("excited with (", 2);
	ft_putendl_fd("error", 2);
	ft_putnbr_fd(err_no, 2);
	ft_putstr_fd("): ", 2);
	ft_putendl_fd(err, 2);
	exit(err_no);
}
