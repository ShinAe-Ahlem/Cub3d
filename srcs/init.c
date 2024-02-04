#include "../includes/game.h"

void initGame(t_game *game)
{
    game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error("ERROR_MLX");
    window_size_setting(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->window_x), (game->window_y),
			game->game_name);
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
        free(game->win_ptr);
		ft_error("ERROR_MLX");
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->window_x, game->window_y);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
	&game->img.line_len, &game->img.endian);
}