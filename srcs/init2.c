/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:37:16 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 14:37:26 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_game_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_error("ERROR_MLX");
		exit(EXIT_FAILURE);
	}
	window_size_setting(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->window_x),
			(game->window_y), game->game_name);
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		ft_error("ERROR_MLX");
	}
}

void	init_image(t_game *game)
{
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->window_x,
			game->window_y);
	if (!game->img.mlx_img)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}
