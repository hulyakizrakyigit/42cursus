/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:35:00 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/10/16 16:27:01 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	i = 0;
	p = (unsigned char *)b;
	val = (unsigned char)c;
	while (i < len)
	{
		p[i] = val;
		i++;
	}
	return (b);
}
