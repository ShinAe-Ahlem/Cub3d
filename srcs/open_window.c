#include "../includes/game.h"

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	printf("\nScreen size : %d x %d\n", game->screen_x, game->screen_y);
    game->window_x = game->screen_x * 0.9;
    game->window_y = game->screen_y * 0.9;
	printf("wing x = %d\n", game->window_x);
	printf("wing y = %d\n", game->window_y);
}

int	ft_create_window(t_game *game)
{
	initGame(game);
	// game->mlx_ptr = mlx_init();
	// if (game->mlx_ptr == NULL)
	// 	return (ERROR_MLX);
    // window_size_setting(game);
	// game->win_ptr = mlx_new_window(game->mlx_ptr,
	// 		(game->window_x), (game->window_y),
	// 		game->game_name);
	// if (game->win_ptr == NULL)
	// {
	// 	mlx_destroy_display(game->mlx_ptr);
    //     free(game->win_ptr);
	// 	return (ERROR_MLX);
	// }
	// game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->window_x, game->window_y);
	// game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
	// &game->img.line_len, &game->img.endian);
	renderGame(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
