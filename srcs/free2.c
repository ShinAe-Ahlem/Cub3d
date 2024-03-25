/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:54:24 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/25 14:07:04 by anouri           ###   ########.fr       */
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

void	free_tex_lines(t_game *game)
{
	if (game->tex_lines)
	{
		if (game->tex_lines[0])
			free(game->tex_lines[0]);
		if (game->tex_lines[1])
			free(game->tex_lines[1]);
		if (game->tex_lines[2])
			free(game->tex_lines[2]);
		if (game->tex_lines[3])
			free(game->tex_lines[3]);
		if (game->tex_lines[4])
			free(game->tex_lines[4]);
		free(game->tex_lines);
	}
	game->tex_lines = NULL;
}
