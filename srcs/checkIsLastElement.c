
#include "../includes/game.h"

void checkIsLastElement(t_game *game)
{
    int i;

    i = game->pos;
    while(game->mapfile[i])
    {

        if (game->mapfile[i] && isEmptyLine(game->mapfile[i]))
        {
            
            while (game->mapfile[i] && !isEmptyLine(game->mapfile[i]))
                i++;
            if (game->mapfile[i] && isEmptyLine(game->mapfile[i]))
            {
                ft_error(ERROR_MAP_SPLITTED);
                //freethis
                exit(EXIT_FAILURE);
            }
        }
        if (game->mapfile[i])
            i++;
    }
}
