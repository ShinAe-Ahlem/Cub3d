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

	i = 0;
	while (i++ < 4)
		mlx_destroy_image(game->mlx_ptr, game->tex[i]);
	i = 0;
	while (i++ < 4)
		free(game->tex);
}

void	free_all(t_game *game)
{
	// mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
	// free(game->img);
	free_tex(game);
	free(game->direction);
	free_table(game->mapfile);
	free_table(game->map);
	free_table(game->texFiles);
	free(game->playerPos);
	free(game->playerPosDelta);
	free(game->cameraPlane);
	// free(game->img->mlx_img);
	free(game->img);
	game->img = NULL;
}
