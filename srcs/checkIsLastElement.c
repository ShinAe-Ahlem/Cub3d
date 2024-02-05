
#include "../includes/game.h"



/*does not detect empty lines that have spaces yet*/

void checkIsLastElement(t_game *game)
{
    int i;

    i = game->pos;
    while(game->mapfile[i])
    {
        if (game->mapfile[i] && !ft_strncmp(game->mapfile[i], "\n", 2))
        {
            while (game->mapfile[i] && !ft_strncmp(game->mapfile[i], "\n", 2))
                i++;
            if (game->mapfile[i] && ft_strncmp(game->mapfile[i], "\n", 2))
            {
                ft_error(ERROR_MAP_SPLITTED);
                //freethis
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }
}


/*checks if the map contains an empty line
this means that it is not the last element in the file
an empty line is a line that == "\n" and that has other line after it
*/

// void checkIsLastElement(t_game *game)
// {
//     t_list *temp;
//     t_list *current;
//     current= game->mapLL;

//     while(current)  /*while not end of file*/
//     {
//         if (!ft_strncmp((current->content),"\n", 2))
//         {
//             if (current->next)
//             {
//                 temp = current->next;
//                 while(temp)
//                 {
//                     if (ft_strncmp((current->content),"\n", 2))
//                     {
//                         ft_error(ERROR_MAP_SPLITTED);
//                         //freethis
//                         exit(EXIT_FAILURE);
//                     }
//                     temp = temp->next;    
//                 }
//             }
//         }
//         current = current->next;
//     }
// }