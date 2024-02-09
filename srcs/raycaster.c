

#include "../includes/game.h"

/*square cubes!

the ray distance is converted to vertical lines that will make the walls

1- use triangles on the horizental grid line =>save distance
2- use triangles on the vertical grid lines => save distance

3- compare both and the one that hits closer will be used as the vertical line's strip

*/

/**/


void drawPlayer(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
    if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		perror("window");
		exit(1);
	}
    ft_putstr_fd("in draw player\n", 1);
    my_mlx_pixel_put(&(game->img), (int)game->player->px, (int)game->player->py, create_rgb(255, 255, 255));
}

int move(int keysym, t_game *game)
{
    if(keysym == XK_a )
    {
        if (game->player->px > 0)
            game->player->px -= 10;
    }
    if (keysym == XK_d)
    {
        if (game->player->py < game->window_x)
            game->player->px += 10;

    }
    if (keysym == XK_w)
    {
        if (game->player->py > 0)
            game->player->py -= 10;
    }
    if (keysym == XK_s)
    {
        if (game->player->py < game->window_y)
            game->player->py += 10;
    }
    return(0);
}

