/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:44:00 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:49:00 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	ray_pos_and_dir(t_game *game, int x)
{
	game->camera_x = 2 * x / (double)game->window_x - 1;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	game->delta_dist_x = fabs(1 / game->ray_dir_x);
	game->delta_dist_y = fabs(1 / game->ray_dir_y);
}

static void	step_and_initial_sidedist(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x)
			* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y)
			* game->delta_dist_y;
	}
}

static void	calculate_wall_height(t_game *game)
{
	game->line_height = (int)(game->window_y / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + game->window_y / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->window_y / 2;
	if (game->draw_end >= game->window_y)
		game->draw_end = game->window_y - 1;
}

static void	texturing_calculation(t_game *game)
{
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x -= floor((game->wall_x));
	game->tex_x = (int)(game->wall_x * TEXWIDTH);
	if (game->side == 0 && game->ray_dir_x > 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	if (game->side == 1 && game->ray_dir_y < 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	game->step = 1.0 * TEXHEIGHT / game->line_height;
	game->tex_pos = (game->draw_start - game->window_y / 2 + game->line_height
			/ 2) * game->step;
}

int	render_next_frame(t_game *game)
{
	int	x;

	x = 0;
	init_image(game);
	while (x < game->window_x)
	{
		ray_pos_and_dir(game, x);
		step_and_initial_sidedist(game);
		perform_dda(game);
		calculate_wall_height(game);
		texturing_calculation(game);
		render(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0,
		0);
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	return (1);
}
