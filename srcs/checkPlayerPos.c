#include "../includes/game.h"

void checkPlayerPos(t_game *game)
{
    int dirFound;
    int i;
    int j;

    dirFound = 0;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'E' || game->map[i][j] == 'W' )
            {
                dirFound += 1;
            }
            j++;
        }
        i++;
    }
    if (dirFound != 1)
    {
        ft_perror(ERROR_MULT_PLA_POS);
        //free
        exit (EXIT_SUCCESS);
    }
}
