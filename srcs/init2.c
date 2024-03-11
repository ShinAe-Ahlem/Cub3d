#include "../includes/game.h"

void initGameWindow(t_game *game)
{
	/******************************************************/
	dprintf(1, "initGame\n");
	
    game->mlx_ptr = mlx_init();
    game->game_name = "Alhem and Shin Ae's World <3";
	if (game->mlx_ptr == NULL)
	{
		ft_error("ERROR_MLX");
		exit(EXIT_FAILURE);
	}
	/******************************************************/
    window_size_setting(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->window_x), (game->window_y),
			game->game_name);
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
        // free(game->win_ptr);
		ft_error("ERROR_MLX");
	}
	// game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->window_x, game->window_y);
	// game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
	// &game->img.line_len, &game->img.endian);
}

void    coordInit(t_coord *coord)
{
    coord->x = 0;
    coord->y = 0;
}

void initImage(t_game *game)
{
	game->img = malloc(1 * sizeof(t_img));
	if(!game->img)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	game->img->mlx_img = mlx_new_image(game->mlx_ptr, game->window_x, game->window_y);
	if(!game->img->mlx_img)
	{
		//freethis
		exit(EXIT_FAILURE);
	}
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp, &game->img->line_len, &game->img->endian);

}