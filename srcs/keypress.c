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
    dprintf(1, "player x = %f", game->player->px);
    dprintf(1, "player y = %f", game->player->py);
    ft_error("moved well\n");
    if (!move(keysym, game))
    {
        printf("player x = %f", game->player->px);
        dprintf(1, "player y = %f", game->player->py);
        renderGame(game);
    }
    return (0);
}