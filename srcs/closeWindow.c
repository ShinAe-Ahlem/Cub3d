/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeWindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:57 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:51:21 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_close_window(t_game *game)
{
	free_all(game);
	printf("\nNow closed %s. Thank you for playing!\n\n", game->game_name);
	exit(EXIT_SUCCESS);
}

void	close_event(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, esc_close_window, game);
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_close_window, game);
}
