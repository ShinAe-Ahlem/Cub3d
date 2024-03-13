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

bool isMap(t_game *game, char *line) //needs to be enhanced, using all charset such as 1,0,N,S,E,W,I,X,Y
{
//    ft_putstr_fd("\n\n----------------------- Map check BEGIN----------------------- \n\n\n", 1);
    char charset[8] = "01NSEW "; // add char such as X, Y and I if needed (bonus part)
    // (void)game;
    // ft_putstr_fd(line, 1);
    if (charset_finder(charset, line))
        return (true);
    else
    {
        ft_perror(ERROR_NO_MATCH_CHAR);
        sleep(1);
        free_all(game);
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
    dprintf(1,"\nin map chaeck division\n");
    
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
	game->mapLL = NULL;

    while(game->mapfile[game->pos])
    {
        // printf("position in map = %d\n", game->pos);
        if (game->mapfile[game->pos] && game->mapfile[game->pos][0] == '\n')
            game->pos++;
        if (game->mapfile[game->pos] && isDirectionLine(game->mapfile[game->pos]))  //do not change the order of the checking
            checkExportTextures(game);
        else if (game->mapfile[game->pos] && isFloorCeilnigLine(game->mapfile[game->pos]))
            checkFloorCeiling(game);
        else if (game->mapfile[game->pos] && isMap(game, game->mapfile[game->pos]))
        {

            checkIsLastElement(game);
            exportMap(game);
        }
        if (game->mapfile[game->pos])
            game->pos++;/*to be removed later*/ //shinae:or maybe not...
    }
        dprintf(1,"\nafter export\n");
    
    // dprintf(1,"\nin check map elm : tex = %s\n", game->texFiles[0]);
    dprintf(1,"\nbefore map chaeck division\n");

    MapCheckDivision(game);

}