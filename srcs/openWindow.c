/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openWindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:39:21 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:47:01 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	import_textures(t_game *game)
{
	game->tex = (void **)malloc(5 * sizeof(void *));
	if (!game->tex)
	{
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	game->tex[0] = mlx_xpm_file_to_image(game->mlx_ptr, game->tex_files[0],
			&game->width[0], &game->height[0]);
	if (!game->tex[0])
		return (1);
	game->tex[1] = mlx_xpm_file_to_image(game->mlx_ptr, game->tex_files[1],
			&game->width[1], &game->height[1]);
	if (!game->tex[1])
		return (1);
	game->tex[2] = mlx_xpm_file_to_image(game->mlx_ptr, game->tex_files[2],
			&game->width[2], &game->height[2]);
	if (!game->tex[2])
		return (1);
	game->tex[3] = mlx_xpm_file_to_image(game->mlx_ptr, game->tex_files[3],
			&game->width[3], &game->height[3]);
	if (!game->tex[3])
		return (1);
	game->tex[4] = NULL;
	return (0);
}

static void	get_texture_address(t_game *game)
{
	game->tex_address = (int **)malloc(4 * sizeof(int *));
	if (!game->tex_address)
	{
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	game->tex_address[0] = (int *)mlx_get_data_addr(game->tex[0], &game->bpp[0],
			&game->line_len[0], &game->endian[0]);
	game->tex_address[1] = (int *)mlx_get_data_addr(game->tex[1], &game->bpp[3],
			&game->line_len[3], &game->endian[3]);
	game->tex_address[2] = (int *)mlx_get_data_addr(game->tex[2], &game->bpp[1],
			&game->line_len[1], &game->endian[1]);
	game->tex_address[3] = (int *)mlx_get_data_addr(game->tex[3], &game->bpp[2],
			&game->line_len[2], &game->endian[2]);
}

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	game->window_x = TILE * 40;
	game->window_y = TILE * 30;
}

int	ft_create_window(t_game *game)
{
	init_game_window(game);
	if (import_textures(game))
	{
		ft_error("Problem has occured while importing texture\n");
		free_all(game);
	}
	get_texture_address(game);
	mlx_key_hook(game->win_ptr, &handle_move, game);
	close_event(game);
	mlx_loop_hook(game->mlx_ptr, render_next_frame, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
