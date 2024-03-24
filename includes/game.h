/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:01:08 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:47:41 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../includes/color.h"
# include "../includes/error.h"
# include "../includes/function.h"
# include "../includes/game.h"
# include "../libft/libft.h"
# include <../minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct s_game	t_game;
typedef struct s_coord	t_coord;

# define TILE 32
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIDTH 920
# define HEIGHT 700

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct s_game
{
	char				*game_name;
	int					fd;
	void				*mlx_ptr;
	void				**tex;
	int					**tex_address;
	int					tex_num;

	void				*win_ptr;
	int					screen_x;
	int					screen_y;
	int					window_x;
	int					window_y;
	char				**mapfile;
	t_color				floor;
	t_color				ceiling;
	t_list				*map_ll;
	char				**map;
	int					map_char_height;
	int					max_map_width;
	t_coord				*player_pos;
	t_coord				*player_pos_delta;
	float				player_angle;
	t_img				img;
	int					pos;
	int					x;
	int					y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				camera_x;
	double				camera_y;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				step_x;
	double				step_y;
	double				pos_x;
	double				pos_y;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				step;
	double				tex_pos;
	int					tex_x;
	int					tex_y;
	char				**tex_files;
	int					dir;
	int					bpp[4];
	int					line_len[4];
	int					endian[4];
	char				**tex_lines;
	int					width[4];
	int					height[4];
	int					**texg;
}						t_game;

#endif