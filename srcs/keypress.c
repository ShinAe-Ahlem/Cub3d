/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:37:40 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 14:37:41 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	esc_close_window(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_all(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	handle_move(int keysym, t_game *game)
{
	if (!move(keysym, game))
		render_next_frame(game);
	return (0);
}

int	move(int keysym, t_game *game)
{
	double	move_speed;

	move_speed = 0.083;
	up_down(keysym, game);
	lef_right(keysym, game, move_speed);
	forward_backward(keysym, game, move_speed);
	return (0);
}
