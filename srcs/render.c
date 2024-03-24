/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:49 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 15:53:14 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	draw_ceiling(t_game *game, int *y, int x)
{
	int	color2;

	color2 = create_rgb(game->ceiling.red, game->ceiling.green,
			game->ceiling.blue);
	while ((*y) < game->drawStart)
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

	while ((*y) < game->drawEnd)
	{
		game->texY = (int)game->texPos & (texHeight - 1);
		game->texPos += game->step;
		color3 = game->texAddress[game->dir][texHeight * game->texY
			+ game->texX];
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
	y = game->drawEnd;
	draw_floor(game, &y, x);
}
