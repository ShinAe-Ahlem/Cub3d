#include "../includes/game.h"

bool    import_textures(t_game *game) // temporary
{
    int size;

    if (!game->grp)
    {
        //freethis
        exit(EXIT_FAILURE);
    }
    game->grp->north = mlx_xpm_file_to_image(game->mlx_ptr, "./img/xpm/north.xpm",&size, &size);
    game->grp->south = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/south.xpm",&size, &size);
    game->grp->west = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/west.xpm",&size, &size);
    game->grp->east = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/east.xpm",&size, &size);

    game->grp->floor = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/floor.xpm",&size, &size);
    game->grp->wall = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/wall.xpm",&size, &size);
    game->grp->ennemi_one = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/shikwon.xpm",&size, &size);
    if (game->grp->floor == NULL || game->grp->wall == NULL || game->grp->ennemi_one == NULL)
        return (1);
    return (0);
}

void    ft_draw_img(t_game *game)
{
    game->x = 0;
    game->y = 0;
    int width = 0;
    while (game->y < game->mapCharHeight)
    {
        game->x = 0;
        while (game->x < width)
        {
            if (game->map[game->y][game->x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->grp->wall, (TILE * game->x), (TILE * game->y));
            // else if (game->map[game->y][game->x] == '0')
            //     mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->grp->floor, (TILE * game->x), (TILE * game->y));
            game->x++;
        }
        width = ft_strlen(game->map[game->y]);
        game->y++;
    }
}
