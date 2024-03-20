#include "../includes/game.h"


int 	close_window(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_all(game);
	
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	handle_move(int keysym, t_game *game)
{
	if (!move(keysym, game))
		render_next_frame(game);
	return (0);
}
