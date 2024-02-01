


#include "../includes/game.h"

/*

    couleurs R,G,B range [0,255] : 0, 255, 255

*/






void checkFloorCeiling(t_game *game)
{
    int F_flag = 0;
    int C_flag = 0;
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
            if(F_flag)
            {
                printf("double floor found\n");
                /*free game*/
                exit(EXIT_FAILURE);
            }
            F_flag = 1;
            printf("floor found\n");
        }
        else if (!ft_strncmp("C ", game->mapfile[game->pos], 2))
        {
            if(C_flag)
            {
                printf("double floor found\n");
                /*free game*/
                exit(EXIT_FAILURE);
            }
            C_flag = 1;
            printf("ceiling found\n");
        }
        game->pos++;
    }
}
