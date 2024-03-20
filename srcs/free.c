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
	// mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
	// free(game->img);
	free_tex(game);
	if(game->mapfile)
		free_table(game->mapfile);
	if(game->map)
		free_table(game->map);
	// if(game->texFiles)
	// 	free_table(game->texFiles);
	free(game->playerPos);
	free(game->playerPosDelta);
	// mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
	// free(game->img);
	// game->img = NULL;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	game->win_ptr = NULL;
}


void free_part(t_game *game)
{
	free_table(game->map);
	free_table(game->mapfile);
	free_table(game->texFiles);
	free_table(game->texLines);
	free(game->playerPos);
	free(game->playerPosDelta);
}