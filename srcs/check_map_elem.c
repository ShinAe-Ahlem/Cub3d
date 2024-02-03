#include "../includes/game.h"

bool isDirectionLine(char *line)
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


bool isFloorCeilnigLine(char *line)
{
    if (!ft_strncmp("F ", line, 2))
        return(true);
    if (!ft_strncmp("c ", line, 2))
        return(true);
    return(false);
}

bool isMap(char *line) //needs to be enhanced, using all charset such as 1,0,N,S,E,W,I,X,Y
{
    char charset[7] = "01NSEW"; // add char such as X, Y and I if needed (bonus part)
    printf("checking line in isMap : %s", line);
    if (ft_isspace(line[0]))
        return (0);
    if (charset_finder(charset, line))
    {
        printf("Test Print : Map element found\n");
        return (true);
    }
    else
    {
        ft_perror(ERROR_NO_MATCHING_CHAR);
        // free
        exit (EXIT_FAILURE);
    }
}

void checkMapElement(t_game *game)
{
    game->pos = 1;
    while(game->mapfile[game->pos])
    {
        if (game->mapfile[game->pos][0] == '\n')
            game->pos++;
        if (isDirectionLine(game->mapfile[game->pos]))  //do not change the order of the checking
        {
            printf("position in map = %d\n", game->pos);
            checkExportTextures(game);
        }
        else if (isFloorCeilnigLine(game->mapfile[game->pos]))
        {
            printf("position in map = %d\n", game->pos);
            checkFloorCeiling(game);
        }
        else if (isMap(game->mapfile[game->pos]))
        {
            printf("position in map = %d\n", game->pos);
            exportMap(game);

            // checkMap(game); ZIS IS ZE PARSING
        }
        game->pos++;/*to be removed later*/ //shinae:or maybe not...
    }
    LLtoArrayConverter(game);
    checkPlayerPos(game);
    // make a function that makes sure that only one elem among NSEW exists on map
    // check_map(game.mapfile);
    // divide_elem(game);
}