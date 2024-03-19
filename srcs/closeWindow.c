#include "../includes/game.h"

int	ft_close_window(t_game *game)
{
	// Destroy all the loaded images as below:
	//
	// if (game->floor)
	// 	mlx_destroy_image(game->mlx_ptr, game->floor);
	
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	// freethis
	printf("\nNow closed %s. Thank you for playing!\n\n", game->game_name);
	exit(0);
}