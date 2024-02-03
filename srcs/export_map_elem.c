#include "../includes/game.h"

void    exportMap(t_game *game)
{
    t_list  *new;
    
    new = ft_lstnew((char *)(game->mapfile[game->pos]));
    ft_lstadd_back(&(game->mapLL), new);
}

void    LLtoArrayConverter(t_game *game)
{
    t_list  *temp;
    t_list  *temp2;
    int     nbLine;
    int     len;
    int     i;

    temp = game->mapLL;
    temp2 = game->mapLL;
    nbLine = 0;
    i = 0;
    game->map = NULL;
    while (temp != NULL)
    {
        temp = temp->next;
        nbLine++;
    }
    game->map = (char **)malloc((nbLine + 1) * sizeof(char *));
    if (!(game->map))
        return ;
    while (temp2 != NULL)
    {
        len = ft_strlen(temp2->content);
        game->map[i] = ft_strdup(temp2->content);
        i++;
        temp2 = temp2->next;
    }
    game->map[i] = 0;
}
