
#include "../includes/game.h"

void	renderGame(t_game *game)
{
	if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		perror("window");
		exit(1);
	}
	// if (game->mlx_ptr == NULL)
	// 	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	printf("seg here\n");
	printf("wing x = %d", game->window_x);
	printf("wing y = %d", game->window_y);
    drawFloorCeiling(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);
}
