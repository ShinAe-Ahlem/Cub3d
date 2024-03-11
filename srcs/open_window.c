#include "../includes/game.h"

// void init_player(t_game *game)
// {
// 	game->player = malloc(1 * sizeof(t_player));
// 	if (!game->player)
// 	{
// 		//freethis
// 		exit(EXIT_FAILURE);
// 	}
//     game->player->px = 10;
//     game->player->py = 10;
// }

static void importTextures(t_game *game)
{
	int size;
	game->tex = malloc(5 * sizeof(void *));
	if (!game->tex)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	game->tex[0] = mlx_xpm_file_to_image(game->mlx_ptr, "./img/xpm/north.xpm",&size, &size);
	// dprintf(1, "tex[0] = %p\n", game->tex[0]);

	// dprintf(1, "north\n");
	game->tex[1] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/east.xpm",&size, &size);
	// dprintf(1, "east\n");
    game->tex[3] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/south.xpm",&size, &size);
	// dprintf(1, "south\n");
	game->tex[2] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/west.xpm",&size, &size);
	// dprintf(1, "west\n");
	game->tex[4] = NULL;
	// dprintf(1, "null\n");
}

static void getTextureAddress(t_game *game)
{
	

	game->texAddress = (int **)malloc(5 * sizeof(int *));
	if (!game->texAddress)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}

	game->texAddress[0] = (int *)mlx_get_data_addr(game->tex[0],&game->bpp[0],&game->line_len[0],&game->endian[0]);
	// dprintf(1, "%p\n", game->texAddress[0]);

    game->texAddress[1] = (int *)mlx_get_data_addr(game->tex[1],&game->bpp[1],&game->line_len[1],&game->endian[1]);
	// dprintf(1, "%p\n", game->texAddress[1]);

    game->texAddress[2] = (int *)mlx_get_data_addr(game->tex[2],&game->bpp[2],&game->line_len[2],&game->endian[2]);
	// dprintf(1, "%p\n", game->texAddress[2]);
	
    game->texAddress[3] = (int *)mlx_get_data_addr(game->tex[3],&game->bpp[3],&game->line_len[3],&game->endian[3]);
	// dprintf(1, "%p\n", game->texAddress[3]);
	game->texAddress[4] = NULL;
}


void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	game->window_x = TILE *40;
	game->window_y = TILE *30;
}

int	ft_create_window(t_game *game)
{
	initGameWindow(game);
	ft_putstr_fd("in create window\n", 1);
	importTextures(game);
	getTextureAddress(game);
	mlx_loop_hook(game->mlx_ptr, renderNextFrame, game);
	mlx_key_hook(game->win_ptr, &hande_move, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
