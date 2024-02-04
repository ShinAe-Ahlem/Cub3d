#include "../includes/game.h"

bool isDirectionLine(char *line)
{
    if (!ft_strncmp("NO ", line, 3))
        return(true);
    else if (!ft_strncmp("SO ", line, 3))
        return(true);
    else if (!ft_strncmp("WE ", line, 3))
        return(true);
    else if (!ft_strncmp("EA ", line, 3))
        return(true);
    return(false);
}

bool isFloorCeilnigLine(char *line)
{
    if (!ft_strncmp("F ", line, 2))
        return(true);
    if (!ft_strncmp("C ", line, 2))
        return(true);
    return(false);
}

bool isMap(char *line) //needs to be enhanced, using all charset such as 1,0,N,S,E,W,I,X,Y
{
    char charset[8] = "01NSEW "; // add char such as X, Y and I if needed (bonus part)
    printf("checking line in isMap : %s\n", line);
    if (charset_finder(charset, line))
        return (true);
    else
    {
        ft_perror(ERROR_NO_MATCH_CHAR);
        sleep(1);
        // free
        exit (EXIT_FAILURE);
    }
}

void checkMapElement(t_game *game)
{
    game->pos = 0;
    while(game->mapfile[game->pos])
    {
        // printf("inside checkMapElement, line = %s \n", game->mapfile[game->pos]);
        if (game->mapfile[game->pos][0] == '\n')
            game->pos++;
        if (isDirectionLine(game->mapfile[game->pos]))  //do not change the order of the checking
        {
            checkExportTextures(game);
        }
        else if (isFloorCeilnigLine(game->mapfile[game->pos]))
        {
            ft_putstr_fd("\n\n----------------------- Floor Ceiling check BEGIN----------------------- \n\n\n", 1);
            checkFloorCeiling(game);
            ft_putstr_fd("\n----------------------- Floor Ceiling check END----------------------- \n", 1);
        }
        else if (isMap(game->mapfile[game->pos]))
        {
            printf("position in map = %d\n", game->pos);
            exportMap(game);

            // checkMap(game); ZIS IS ZE PARSING
        }
        game->pos++;/*to be removed later*/ //shinae:or maybe not...
    }
    // printf("Check point0\n");
    LLtoArrayConverter(game);
    checkPlayerPos(game);
    zeroBlankContact(game);
    // check_map(game.mapfile);
    // divide_elem(game);
}