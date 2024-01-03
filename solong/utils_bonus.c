/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:39:20 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 20:43:42 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "so_long_bonus.h"

int	strlen_endl(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
//??

static void	set_enemy(t_info *info, int y, int x)
{
	t_enemy	*tmp;

	if (!info->enemies)
	{
		info->enemies = (t_enemy *) malloc(sizeof(t_enemy));
		if (!info->enemies)
			exiterr(45, "info.enemies cannot be allocated", info);
		info->enemies->x = x;
		info->enemies->y = y;
		info->enemies->direction = DIR_RIGHT;
		info->enemies->next = NULL;
	}
	else
	{
		tmp = info->enemies;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_enemy *) malloc(sizeof(t_enemy));
		if (!tmp->next)
			exiterr(46, "info.enemies cannot be allocated", info);
		tmp->next->x = x;
		tmp->next->y = y;
		tmp->next->direction = DIR_RIGHT;
		tmp->next->next = NULL;
	}
}

void	set_enemies(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (M_ENEMY == info->map->board[y][x])
				set_enemy(info, y, x);
			x++;
		}
		y++;
	}
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

void	fill_flood(int x, int y, t_map *map)
{
	if (x < 0 || x > map->width - 1 || y < 0 || y > map->height - 1)
		return ;
	if (map->board[y][x] != M_WALL && map->board[y][x] != 'F')
	{
		map->board[y][x] = 'F';
		fill_flood(x, y - 1, map);
		fill_flood(x, y + 1, map);
		fill_flood(x - 1, y, map);
		fill_flood(x + 1, y, map);
	}
}
