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


 int hande_move(int keysym, t_game *game)
{
    dprintf(1, "player x = %d", game->playerPos->x);
    dprintf(1, "player y = %d", game->playerPos->y);
    ft_error("moved well\n");
    if (!move(keysym, game))
    {
        printf("player x = %d\n", game->playerPos->x);
        dprintf(1, "player y = %d\n", game->playerPos->y);
        renderNextFrame(game);
    }
    return (0);
}