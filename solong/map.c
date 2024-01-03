/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:29:25 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 15:18:10 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "stdlib.h"
#include "library/libft/libft.h"
#include "so_long.h"

static void	check_border(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		if (y == 0 || y == info->map->height -1)
		{
			while (x < info->map->width)
				if (info->map->board[y][x++] != M_WALL)
					exiterr(14, "invalid map border", info);
		}
		else
		{
			if (info->map->board[y][x] != M_WALL
				|| info->map->board[y][info->map->width -1] != M_WALL)
				exiterr(14, "invalid map border", info);
		}
		y++;
	}
}

static void	set_boundaries(t_info *info)
{
	int		height;
	int		width;
	char	*line;
	int		fd;

	fd = open(info->map->path, O_RDONLY);
	if (fd == -1)
		exiterr(6, "map cannot be opened", info);
	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (width != 0)
			check_width(info, width, line);
		width = strlen_endl(line);
		height++;
		free(line);
	}
	if (close(fd) == -1)
		exiterr(7, "map file cannot be closed", info);
	info->map->height = height;
	info->map->width = width;
}

static void	init_map(t_info *info, char *map_path)
{
	char	*line;
	int		fd;
	int		i;

	info -> map -> path = map_path;
	set_boundaries(info);
	fd = open(info -> map -> path, O_RDONLY);
	if (fd == -1)
		exiterr(8, "map cannot be opened", info);
	info -> map -> board = (char **)malloc(info->map->height * sizeof(char *));
	if (!info -> map -> board)
		exiterr(9, "info.map.board cannot be allocated", info);
	i = 0;
	while (i < info->map->height)
	{
		line = get_next_line(fd);
		if (!line)
			exiterr(10, "map line cannot be read", info);
		info->map->board[i] = line;
		if (!info->map->board[i])
			exiterr(11, "info.map.board item cannot be allocated", info);
		i++;
	}
	if (close(fd) == -1)
		exiterr(15, "map file cannot be closed", info);
}

void	check_map(t_info *info, char *map_path)
{
	char	*file_ext;

	if (!map_path)
		exiterr(3, "map path cannot be null", info);
	file_ext = ft_strnstr(map_path, ".ber", ft_strlen(map_path));
	if (!file_ext || ft_strncmp(file_ext, ".ber", ft_strlen(file_ext)) != 0)
		exiterr(4, "invalid map file, need a file with '.ber'", info);
	info->map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!info->map)
		exiterr(5, "info.map cannot be allocated", info);
	init_map(info, map_path);
	check_border(info);
	check_items(info);
}
