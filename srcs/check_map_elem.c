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
    // ft_putstr_fd(line, 1);
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
    bool found_directions;
    bool found_FC;
    bool found_map;

    found_directions = false;
    found_FC = false;
    found_map = false;
    while(game->mapfile[game->pos])
    {
        // printf("position in map = %d\n", game->pos);
        // printf("inside checkMapElement, line = %s \n", game->mapfile[game->pos]);
        if (game->mapfile[game->pos] && game->mapfile[game->pos][0] == '\n')
        {
            game->pos++;
            // printf("position in map = %d\n", game->pos);
        }
        if (game->mapfile[game->pos] && isDirectionLine(game->mapfile[game->pos]))  //do not change the order of the checking
        {
            ft_putstr_fd("\n\n----------------------- is direction line check BEGIN----------------------- \n\n\n", 1);
            checkExportTextures(game);
            found_directions = true;
            ft_putstr_fd("\n----------------------- is direction line check END----------------------- \n", 1);

        }
        else if (game->mapfile[game->pos] && isFloorCeilnigLine(game->mapfile[game->pos]))
        {
            ft_putstr_fd("\n\n----------------------- Floor Ceiling check BEGIN----------------------- \n\n\n", 1);
            checkFloorCeiling(game);
            found_FC = true;
            ft_putstr_fd("\n----------------------- Floor Ceiling check END----------------------- \n", 1);

        }
        else if (game->mapfile[game->pos] && isMap(game->mapfile[game->pos]))
        {
            checkIsLastElement(game);
            exportMap(game);
        }
        game->pos++;/*to be removed later*/ //shinae:or maybe not...
    }
    // checkMap(game); ZIS IS ZE PARSING this should regroup following map checking functions
    // found_map = true; /*if checkMap is ok*/
    // if (!(found_directions && found_FC && found_map)) /*to be enhanced later*/
    // {
    //     //freethis
    //     ft_error("something is missing in the file\n");
    // }
    LLtoArrayConverter(game);
    checkPlayerPos(game);
    zeroBlankContact(game);
    floodFillCheck(game);
    // check_map(game.mapfile);
    // divide_elem(game);
}