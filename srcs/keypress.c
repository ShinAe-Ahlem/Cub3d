#include "../includes/game.h"

int	handle_keypress(int keysym, t_game *game)
{
    if (keysym == XK_Escape)
    {
        free_all(game);
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        game->win_ptr = NULL;
        exit(EXIT_SUCCESS);
    }
 
    return (0);
}

int hande_move(int keysym, t_game *game)
{
    if (!move(keysym, game))
        renderNextFrame(game);
    return (0);
}