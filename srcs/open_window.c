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
	renderGame(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
