/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:19:41 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 17:31:25 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "library/minilibx/mlx.h"

static void	put_image(t_info *info, char c, int x, int y)
{
	if (c != M_WALL)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.z0, x, y);
	if (c == M_WALL)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.o1, x, y);
	if (c == M_PLAYER)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.p, x, y);
	if (c == M_COLLECTIBLE)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.c, x, y);
	if (c == M_EXIT)
		mlx_put_image_to_window(info->mlx, info->win, info->imgs.e, x, y);
}

void	put_images(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			put_image(info, info->map->board[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	init_images(t_info *info)
{
	int	x;
	int	y;

	info->imgs.p = mlx_xpm_file_to_image(info->mlx,
			"textures/right.xpm", &x, &y);
	if (!info->imgs.p)
		exiterr(34, "'textures/right.xpm' file cannot be found", info);
	info->imgs.e = mlx_xpm_file_to_image(info->mlx,
			"textures/exit_1.xpm", &x, &y);
	if (!info->imgs.e)
		exiterr(35, "'textures/exit_1.xpm' file cannot be found", info);
	info->imgs.c = mlx_xpm_file_to_image(info->mlx,
			"textures/collect.xpm", &x, &y);
	if (!info->imgs.c)
		exiterr(36, "'textures/collect.xpm' file cannot be found", info);
	info->imgs.z0 = mlx_xpm_file_to_image(info->mlx,
			"textures/space.xpm", &x, &y);
	if (!info->imgs.z0)
		exiterr(37, "'textures/space.xpm' file cannot be found", info);
	info->imgs.o1 = mlx_xpm_file_to_image(info->mlx,
			"textures/wall.xpm", &x, &y);
	if (!info->imgs.o1)
		exiterr(38, "'textures/wall.xpm' file cannot be found", info);
}
