/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:01 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 15:18:24 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "so_long.h"
#include "library/minilibx/mlx.h"
#include "library/libft/libft.h"

int	exit_game(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	dispose(info);
	ft_printf("exited\n");
	exit(EXIT_SUCCESS);
}

static int	check_next_tile(t_info *info, int direction, char tile)
{
	if (direction == DIR_RIGHT)
	{
		if (info->map->board[info->player.y][info->player.x + 1] == tile)
			return (1);
	}
	else if (direction == DIR_LEFT)
	{
		if (info->map->board[info->player.y][info->player.x - 1] == tile)
			return (1);
	}
	else if (direction == DIR_DOWN)
	{
		if (info->map->board[info->player.y + 1][info->player.x] == tile)
			return (1);
	}
	else if (direction == DIR_UP)
	{
		if (info->map->board[info->player.y - 1][info->player.x] == tile)
			return (1);
	}
	return (0);
}

static int	check_move(t_info *info, int direction)
{
	if (check_next_tile(info, direction, M_WALL))
		return (0);
	if (check_next_tile(info, direction, M_COLLECTIBLE))
		info->collectibles--;
	if (check_next_tile(info, direction, M_EXIT)
		&& info->collectibles == 0)
	{
		info->player.moves++;
		ft_printf("you won!\ntotal moves: %d\n", info->player.moves);
		exit_game(info);
	}
	info->player.moves++;
	ft_printf("moves: %d\n", info->player.moves);
	return (1);
}

static void	move(t_info *info, int direction)
{
	if (!check_move(info, direction))
		return ;
	if (info->player.x == info->exit.x
		&& info->player.y == info->exit.y)
		info->map->board[info->player.y][info->player.x] = M_EXIT;
	else
		info->map->board[info->player.y][info->player.x] = M_GROUND;
	if (direction == DIR_RIGHT)
		info->player.x++;
	else if (direction == DIR_LEFT)
		info->player.x--;
	else if (direction == DIR_DOWN)
		info->player.y++;
	else if (direction == DIR_UP)
		info->player.y--;
	info->map->board[info->player.y][info->player.x] = M_PLAYER;
}

int	key_hook(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit_game(info);
	else if (key == KEY_A || key == KEY_LEFT)
		move(info, DIR_LEFT);
	else if (key == KEY_D || key == KEY_RIGHT)
		move(info, DIR_RIGHT);
	else if (key == KEY_W || key == KEY_UP)
		move(info, DIR_UP);
	else if (key == KEY_S || key == KEY_DOWN)
		move(info, DIR_DOWN);
	put_images(info);
	return (0);
}
