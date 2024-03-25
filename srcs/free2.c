/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:54:24 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/25 11:24:39 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	free_tex_files(t_game *game)
{
	if (game->tex_files)
	{
		if (game->tex_files[0])
			free(game->tex_files[0]);
		if (game->tex_files[1])
			free(game->tex_files[1]);
		if (game->tex_files[2])
			free(game->tex_files[2]);
		if (game->tex_files[3])
			free(game->tex_files[3]);
		if (game->tex_files[4])
			free(game->tex_files[4]);
		free(game->tex_files);
	}
	game->tex_files = NULL;
}
