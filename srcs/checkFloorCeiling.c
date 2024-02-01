


#include "../includes/game.h"

void checkFloorCeiling(t_game *game)
{
    int i;
    i = game->pos;
    // while(game->mapfile[game->pos][0] == '\n')
    //     game->pos++;
    while(game->mapfile[game->pos] != NULL)
    {
        printf("here\n");
        if (game->mapfile[game->pos][0] == '\n')
        {
            ft_error("Enter found\n");
            break ;
        }
        if (!ft_strncmp("F ", game->mapfile[game->pos], 2))
        {
            printf("floor found\n");
            /*check line if ok?*/
        }
        else if (!ft_strncmp("C ", game->mapfile[game->pos], 2))
            printf("ceiling found\n");
            /*check line is ok>*/
        game->pos++;
    }
}