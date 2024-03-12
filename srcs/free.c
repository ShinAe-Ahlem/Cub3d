#include "../includes/game.h"

void freeCharArray(char ***array)
{
    int i = 0;

    while ((*array)[i] != NULL)
    {
        free((*array)[i]);
        i++;
    }
    free(*array);
    *array = NULL;
}

void free_all(t_game *game)
{
    // mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
    // free(game->img);
    free(game->direction);
    free(game->grp);
    free(game->mapfile);
    free(game->map);
    
    free(game->playerPos);
    free(game->playerPosDelta);
    free(game->cameraPlane);
    game->img = NULL;
}