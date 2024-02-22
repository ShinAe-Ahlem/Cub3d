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
   // ft_putstr_fd("\n\n----------------------- Map check BEGIN----------------------- \n\n\n", 1);
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

static void EpurArray(t_game *game)
{
       // dprintf(1,"\n********** EpurArray begin*********\n");
    int i;
    size_t lastOnePos;
    char **new;
    new = malloc((game->mapCharHeight + 1) * sizeof(char *));
    if (!new)
    {
        /*free this*/
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while(game->map[i])
    {
        lastOnePos= ft_strlen(game->map[i]);
       // dprintf(1, "len de map[%d] = %zu\n", i, ft_strlen(game->map[i]));
       // dprintf(1, "lastOnePOs initialized to = %zu\n", lastOnePos);
        if (game->map[i][lastOnePos -1 ] == '\n')
           // dprintf(1, "\n**********************************************************************\n");
        lastOnePos--;
       // dprintf(1, "lastOnePOs = %zu\n", lastOnePos);
        while(game->map[i][lastOnePos] == ' ' || game->map[i][lastOnePos] == '\n')
            lastOnePos--;
       // dprintf(1, "lastOnePOs = %zu\n", lastOnePos);
        if (lastOnePos == ft_strlen(game->map[i]) - 2)
        {
           // dprintf(1, "no sapces found\n");
            new[i] = ft_strdup(game->map[i]);
           // dprintf(1, "new[%d] = %s\n",i, new[i]);
        }
        else
        {
            new[i] = ft_substr(game->map[i], 0, lastOnePos + 2);
            new[i][lastOnePos + 1] = '\n';
           // dprintf(1, "len de new[%d] = %zu\n", i, ft_strlen(new[i]));
           // dprintf(1, "new[%d] = %s\n",i, new[i]);
        }
        i++;
    }
    new[i] = NULL;
    //// dprintf(1, "in Epur");
    // print_char_table(new);
    free_table(game->map);
    game->map = new;
   // dprintf(1,"\n********** EpurArray end*********\n");

}

void getMaxWidth(t_game *game)
{
    int i;
    i = 0;
    game->maxMapWidth = 0;
    while(game->map[i])
    {
        if (ft_strlen(game->map[i]) > (size_t)game->maxMapWidth)
            game->maxMapWidth = ft_strlen(game->map[i]);
        i++;
    }
}

void    MapCheckDivision(t_game *game)
{
    LLtoArrayConverter(game);
    checkPlayerPos(game);
    zeroBlankContact(game);
    floodFillCheck(game);
    EpurArray(game);
    getMaxWidth(game);
}

void checkMapElement(t_game *game)
{
    game->pos = 0;
    //bool found_directions;
    //bool found_FC;
    //bool found_map;
	game->mapLL = NULL;

    //found_directions = false;
   // found_FC = false;
    //found_map = false;
    while(game->mapfile[game->pos])
    {
        // printf("position in map = %d\n", game->pos);
        if (game->mapfile[game->pos] && game->mapfile[game->pos][0] == '\n')
        {
            game->pos++;
            // printf("position in map = %d\n", game->pos);
        }
        if (game->mapfile[game->pos] && isDirectionLine(game->mapfile[game->pos]))  //do not change the order of the checking
        {
            ft_putstr_fd("\n\n----------------------- is direction line check BEGIN----------------------- \n\n\n", 1);
            checkExportTextures(game);
           // found_directions = true;
            ft_putstr_fd("\n----------------------- is direction line check END----------------------- \n", 1);

        }
        else if (game->mapfile[game->pos] && isFloorCeilnigLine(game->mapfile[game->pos]))
        {
            ft_putstr_fd("\n\n----------------------- Floor Ceiling check BEGIN----------------------- \n\n\n", 1);
            checkFloorCeiling(game);
         //   found_FC = true;
            ft_putstr_fd("\n----------------------- Floor Ceiling check END----------------------- \n", 1);

        }
        else if (game->mapfile[game->pos] && isMap(game->mapfile[game->pos]))
        {
            // printf("inside checkMapElement, isMap Loop, line = %s \n", game->mapfile[game->pos]);
            checkIsLastElement(game);
            exportMap(game);
        }
        if (game->mapfile[game->pos])
            game->pos++;/*to be removed later*/ //shinae:or maybe not...
    }
    MapCheckDivision(game);
    ft_putstr_fd("\n\nmaxMapWidth = ", 1);
    ft_putnbr_fd(game->maxMapWidth, 1);
    ft_putstr_fd("\n\n", 1);
    ft_putstr_fd("\n\n----------------------- Map check END----------------------- \n\n\n", 1);
}