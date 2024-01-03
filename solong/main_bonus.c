/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:00:27 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 20:48:17 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "library/minilibx/mlx.h"
#include "so_long_bonus.h"

static void	init_info(t_info *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map = NULL;
	info->enemies = NULL;
	info->imgs.c = NULL;
	info->imgs.e = NULL;
	info->imgs.o1 = NULL;
	info->imgs.p1 = NULL;
	info->imgs.p2 = NULL;
	info->imgs.p3 = NULL;
	info->imgs.p4 = NULL;
	info->imgs.p5 = NULL;
	info->imgs.p6 = NULL;
	info->imgs.z0 = NULL;
	info->collectibles = 0;
	info->player.current_img = 1;
	info->player.moves = 0;
}

static void	window(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		exiterr(32, "mlx cannot be initialized", info);
	info->win = mlx_new_window(info->mlx, info->map->width * 64,
			info->map->height * 64, "s o _ l o n g");
	if (!info->win)
		exiterr(33, "window cannot be opened", info);
	init_images(info);
	put_imgs(info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_hook(info->win, BTN_EXIT, 0, exit_game, info);
	mlx_loop_hook(info->mlx, loop_hook, info);
	write_score(info);
	mlx_loop(info->mlx);
}

int	main(int ac, char *av)
{
	t_info	*info;

	if (ac != 2)
		exiterr(1, "invalid argument", NULL);
	info = (t_info *) malloc(sizeof(info));
	if (!info)
		exiterr(2, "info cannot be allocated", info);
	init_info(info);
	check_map(info, av[1]);
	if (info->map->height > 20 || info->map->width > 40)
		exiterr(31, "map is too big in order to play", info);
	window(info);
}
