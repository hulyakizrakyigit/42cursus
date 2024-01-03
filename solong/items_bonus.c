/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:03:41 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 20:45:19 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "library/libft/libft.h"

static int	count_chr(t_info *info, char c)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (c == info->map->board[y][x])
				count++;
			set_items(info, x, y);
			x++;
		}
		y++;
	}
	return (count);
}

static void	check_chars(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (!ft_strchr(M_ELEMENTS, info->map->board[y][x]))
				exiterr(17, "invalid map, unexpected character", info);
			x++;
		}
		y++;
	}
}

static int	ft_count_chr_map(t_map *map, char c)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (c == map->board[y][x])
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	check_game(t_info *info)
{
	t_map	tmp;
	int		i;

	tmp.height = info->map->height;
	tmp.width = info->map->width;
	i = 0;
	tmp.board = (char **) ft_calloc(tmp.height, sizeof(char *));
	if (!tmp.board)
		exiterr(21, "tmp.board cannot be allocated", info);
	while (i < tmp.height)
	{
		tmp.board[i] = ft_strdup(info->map->board[i]);
		i++;
	}
	fill_flood(info->player.x, info->player.y, &tmp);
	if ((count_chr_map(&tmp, M_PLAYER) != 0)
		|| (count_chr_map(&tmp, M_EXIT) != 0)
		|| (count_chr_map(&tmp, M_COLLECTIBLE) != 0))
		exiterr(21, "invalid map, unreachable character", info);
	i = 0;
	while (i < tmp.height)
		free(tmp.board[i++]);
}

void	check_items(t_info *info)
{
	check_chars(info);
	if (count_chr(info, M_PLAYER) != 1)
		exiterr(18, "invalid player count", info);
	if (count_chr(info, M_EXIT != 1))
		exiterr(19, "invalid EXİT count", info);
	info->collectibles = count_chr(info, M_COLLECTIBLE);
	if (info->collectibles < 1)
		exiterr(20, "invalid collectible count", info);
	set_enemies(info);
	check_game(info);
}
