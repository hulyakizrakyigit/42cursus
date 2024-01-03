/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:44 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 15:21:38 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "so_long.h"

static void	dispose_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	if (map->board)
		while (i < map->height)
			free(map->board[i++]);
	free(map->board);
	free(map);
}

void	dispose(t_info *info)
{
	if (!info)
		return ;
	dispose_map(info->map);
}
