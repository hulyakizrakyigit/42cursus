/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:49:17 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 20:58:33 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "library/minilibx/mlx.h"

static void	put_player_img_to_window(t_info *info, int x, int y)
{
	if (info->player.current_img == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.p1, x, y);
	if (info->player.current_img == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.p2, x, y);
	if (info->player.current_img == 3)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.p3, x, y);
	if (info->player.current_img == 4)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.p4, x, y);
}

static void	ft_put_img(t_info *info, char c, int x, int y)
{
	if (c != M_WALL)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.z0, x, y);
	if (c == M_WALL)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.o1, x, y);
	if (c == M_PLAYER)
		put_player_img_to_window(info, x, y);
	if (c == M_COLLECTIBLE)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.c, x, y);
	if (c == M_EXIT)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.e, x, y);
	if (c == M_ENEMY)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.x, x, y);
}

void	ft_put_imgs(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			ft_put_img(info, info->map->board[y][x], x * 64, y * 64);
			x++;
		}
		x++;
	}
}

static void	ft_init_player_imgs(t_info *info, int *x, int *y)
{
	info->imgs.p1 = mlx_xpm_file_to_image(info->mlx,
			"textures/player1.xpm", x, y);
	if (!info->imgs.p1)
		ft_exiterr(38, "'textures/player1.xpm' file cannot be found", info);
	info->imgs.p2 = mlx_xpm_file_to_image(info->mlx,
			"textures/player2.xpm", x, y);
	if (!info->imgs.p2)
		ft_exiterr(39, "'textures/player2.xpm' file cannot be found", info);
	info->imgs.p3 = mlx_xpm_file_to_image(info->mlx,
			"textures/player3.xpm", x, y);
	if (!info->imgs.p3)
		ft_exiterr(40, "'textures/player3.xpm' file cannot be found", info);
	info->imgs.p4 = mlx_xpm_file_to_image(info->mlx,
			"textures/player4.xpm", x, y);
	if (!info->imgs.p4)
		ft_exiterr(41, "'textures/player4.xpm' file cannot be found", info);
	info->imgs.p5 = mlx_xpm_file_to_image(info->mlx,
			"textures/player5.xpm", x, y);
}

void	init_images(t_info *info)
{
	int	x;
	int	y;

	init_player_imgs(info, &x, &y);
	info->imgs.e = mlx_xpm_file_to_image(info->mlx,
			"textures/exit_1.xpm", &x, &y);
	if (!info->imgs.e)
		exiterr(34, "'textures/exit_1.xpm' file cannot be found", info);
	info->imgs.c = mlx_xpm_file_to_image(info->mlx,
			"textures/collect.xpm", &x, &y);
	if (!info->imgs.c)
		exiterr(35, "'textures/collect.xpm' file cannot be found", info);
	info->imgs.z0 = mlx_xpm_file_to_image(info->mlx,
			"textures/space.xpm", &x, &y);
	if (!info->imgs.z0)
		exiterr(36, "'textures/space.xpm' file cannot be found", info);
	info->imgs.o1 = mlx_xpm_file_to_image(info->mlx,
			"textures/wall.xpm", &x, &y);
	if (!info->imgs.o1)
		exiterr(37, "'textures/wall.xpm' file cannot be found", info);
	info->imgs.x = mlx_xpm_file_to_image(info->mlx,
			"textures/enemy.xpm", &x, &y);
	if (!info->imgs.x)
		exiterr(44, "'textures/enemy.xpm' file cannot be found", info);
}
