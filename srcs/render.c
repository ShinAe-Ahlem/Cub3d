/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:49 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:46:35 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	draw_ceiling(t_game *game, int *y, int x)
{
	int	color2;

	color2 = create_rgb(game->ceiling.red, game->ceiling.green,
			game->ceiling.blue);
	while ((*y) < game->draw_start)
	{
		my_mlx_pixel_put(&game->img, x, *y, color2);
		(*y)++;
	}
}

static void	draw_floor(t_game *game, int *y, int x)
{
	int	color1;

	color1 = create_rgb(game->floor.red, game->floor.green, game->floor.blue);
	while (*y < game->window_y - 1)
	{
		my_mlx_pixel_put(&game->img, x, *y, color1);
		(*y)++;
	}
}

static void	draw_wall(t_game *game, int *y, int x)
{
	int	color3;

	while ((*y) < game->draw_end)
	{
		game->tex_y = (int)game->tex_pos & (TEXHEIGHT - 1);
		game->tex_pos += game->step;
		color3 = game->tex_address[game->dir][TEXHEIGHT * game->tex_y
			+ game->tex_x];
		if (game->side == 1)
			color3 = (color3 >> 1) & 8355711;
		my_mlx_pixel_put(&game->img, x, *y, color3);
		(*y)++;
	}
}

void	render(t_game *game, int x)
{
	int	y;

	y = 0;
	draw_ceiling(game, &y, x);
	draw_wall(game, &y, x);
	y = game->draw_end;
	draw_floor(game, &y, x);
}
