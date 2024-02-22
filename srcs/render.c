#include "../includes/game.h"


void	renderGame(t_game *game)
{
    ft_putstr_fd("in render game", 1);

	if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		perror("window");
		exit(1);
	}
	if (game->mlx_ptr != NULL)
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
    drawFloorCeiling(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);
	drawPlayer(game);
	//ft_draw_img(game);
    ft_putstr_fd("in render game", 1);
}
