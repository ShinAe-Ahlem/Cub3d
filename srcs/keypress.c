#include "../includes/game.h"

int	handle_keypress(int keysym, t_game *game)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        game->win_ptr = NULL;
    }
    return (0);
}
