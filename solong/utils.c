/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:59:00 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/21 15:17:44 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_endl(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	check_width(t_info *info, int old_width, char *line)
{
	if (!line)
		return ;
	if (old_width != strlen_endl(line))
		exiterr(12, "invalid map, line lengths are incompatible", info);
}

void	set_items(t_info *info, int x, int y)
{
	if (info->map->board[y][x] == M_PLAYER)
	{
		info->player.x = x;
		info->player.y = y;
		info->player.moves = 0;
	}
	if (info->map->board[y][x] == M_EXIT)
	{
		info->exit.x = x;
		info->exit.y = y;
	}
}

void	f_fill_flood(int x, int y, t_map *map)
{
	if (x < 0 || x > map->width - 1 || y < 0 || y > map->height - 1)
		return ;
	if (map->board[y][x] != 1 && map->board[y][x] != 'F')
	{
		map->board[y][x] = 'F';
		f_fill_flood(x, y - 1, map);
		f_fill_flood(x, y + 1, map);
		f_fill_flood(x - 1, y, map);
		f_fill_flood(x + 1, y, map);
	}
}
