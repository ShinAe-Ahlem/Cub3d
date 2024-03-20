#include "../includes/game.h"

int	ft_close_window(t_game *game)
{
	free_all(game);
	printf("\nNow closed %s. Thank you for playing!\n\n", game->game_name);
	exit(EXIT_SUCCESS);
}

void close_event(t_game *game)
{
    mlx_hook(game->win_ptr, 2, 1L<<0, close_window, game);
	mlx_hook(game->win_ptr, DestroyNotify, 0, ft_close_window, game);
}
