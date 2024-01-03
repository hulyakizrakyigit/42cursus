/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:01:48 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/22 18:06:02 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define M_ENEMY 'X'
# define M_WALL '1'
# define M_GROUND '0'
# define M_COLLECTIBLE 'C'
# define M_PLAYER 'P'
# define M_EXIT 'E'
# define M_ELEMENTS "X10CPE"

# define BTN_EXIT 17

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define DIR_LEFT 	42
# define DIR_RIGHT 	31
# define DIR_UP 	21
# define DIR_DOWN 	1337

typedef struct s_map
{
	char	*path;
	int		width;
	int		height;
	char	**board;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	current_img;
}			t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}			t_exit;

typedef struct s_imgs
{
	void	*e;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*p5;
	void	*p6;
	void	*o1;
	void	*z0;
	void	*c;
	void	*x;
}			t_imgs;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				direction;
	struct s_enemy	*next;
}			t_enemy;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	player;
	t_enemy		*enemies;
	t_imgs		imgs;
	int			collectibles;
	t_exit		exit;
}				t_info;

void	exiterr(int err_no, char *err, t_info *info);
void	dispose(t_info *info);
void	check_map(t_info *info, char *map_path);
int		strlen_endl(char *str);
void	check_elements(t_info *info);
void	fill_flood(int x, int y, t_map *map);
void	init_images(t_info *info);
int		exit_game(t_info *info);
int		key_hook(int key, t_info *info);
void	put_imgs(t_info *info);
void	set_items(t_info *info, int w, int h);
int		loop_hook(t_info *info);
void	move_enemies(t_info *info, int change_dir);
void	player_anim(t_info *info);
void	check_collision(t_info *info);
void	write_score(t_info *info);
void	set_enemies(t_info *info);

#endif
