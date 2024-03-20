#include "../includes/game.h"

int	ft_close_window(t_game *game)
{
	free_all(game);
	printf("\nNow closed %s. Thank you for playing!\n\n", game->game_name);
	exit(EXIT_SUCCESS);
}