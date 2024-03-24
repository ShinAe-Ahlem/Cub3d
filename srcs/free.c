/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:34:24 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 14:34:25 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	free_char_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

void	free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = (lst)->next;
		free(lst);
		lst = temp;
	}
	lst = NULL;
}

static void	free_tex(t_game *game)
{
	int	i;

	i = -1;
	if (game->tex)
	{
		while (++i < 4)
			mlx_destroy_image(game->mlx_ptr, game->tex[i]);
		free(game->tex[4]);
		free(game->tex);
	}
}

void	free_all(t_game *game)
{
	free_tex(game);
	free_table(game->mapfile);
	free_table(game->map);
	free_table(game->texFiles);
	free_table(game->texLines);
	free(game->texAddress);
	free_lst(game->mapLL);
	free(game->playerPos);
	free(game->playerPosDelta);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->win_ptr = NULL;
}

void	free_part(t_game *game)
{
	free_lst(game->mapLL);
	free_table(game->map);
	free_table(game->mapfile);
	free_table(game->texFiles);
	free_table(game->texLines);
	free(game->playerPos);
	free(game->playerPosDelta);
}
