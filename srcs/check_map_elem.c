#include "../includes/game.h"

bool isDirectionLine(line)
{
    if (!ft_strncmp("NO ", line, 3))
        return(true);
    if (!ft_strncmp("SO ", line, 3))
        return(true);
    if (!ft_strncmp("WE ", line, 3))
        return(true);
    if (!ft_strncmp("EA ", line, 3))
        return(true);
    return(false);
}


bool isFloorCeilnigLine(line)
{
    if (!ft_strncmp("F ", line, 2))
        return(true);
    if (!ft_strncmp("c ", line, 2))
        return(true);
    return(false);
}

void checkMapElement(t_game *game)
{

    game->pos = 0;
    while(game->mapfile[game->pos])
    {
        if (game->mapfile[game->pos][0] == '\n')
            game->pos++;

        if (isDirectionLine(game->mapfile[game->pos]))
            checkExportTextures(game);
        else if (isFloorCeilnigLine(game->mapfile[game->pos]))
            checkFloorCeiling(game);
    }
    // check_map(game.mapfile);
    // divide_elem(game);
}

