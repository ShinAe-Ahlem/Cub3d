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
	dprintf(1, "north\n");

    game->tex[1] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/south.xpm",&size, &size);
	dprintf(1, "south\n");
    
	game->tex[2] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/west.xpm",&size, &size);
	dprintf(1, "west\n");
    
	game->tex[3] = mlx_xpm_file_to_image(game->mlx_ptr, "img/xpm/east.xpm",&size, &size);
	dprintf(1, "east\n");
	
	game->tex[4] = NULL;
	dprintf(1, "null\n");
}

static void getTextureAddress(t_game *game)
{
	int				bpp[4];
	int				line_len[4];
	int				endian[4];

	game->texAddress = malloc(5 * sizeof(char *));
	if (!game->texAddress)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	dprintf(1, "getTexture address\n");
	game->texAddress[0] = mlx_get_data_addr(game->tex[0], &bpp[0], &line_len[0], &endian[0]);
	dprintf(1, "%p\n", game->texAddress[0]);

    game->texAddress[1] = mlx_get_data_addr(game->tex[1], &bpp[1], &line_len[1], &endian[1]);
	dprintf(1, "%p\n", game->texAddress[1]);

    game->texAddress[2] = mlx_get_data_addr(game->tex[2], &bpp[2], &line_len[2], &endian[2]);
	dprintf(1, "%p\n", game->texAddress[2]);
	
    game->texAddress[3] = mlx_get_data_addr(game->tex[3], &bpp[3], &line_len[3], &endian[3]);
	dprintf(1, "%p\n", game->texAddress[3]);
	
	game->texAddress[4] = NULL;
	dprintf(1, "getTexture address\n");

}

// static void 	generateTex(t_game *game)
// {
// 	for(int x = 0; x < texWidth; x++)
// 	{

// 		for(int y = 0; y < texHeight; y++)
// 		{
// 			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
// 			//int xcolor = x * 256 / texWidth;
// 			int ycolor = y * 256 / texHeight;
// 			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
// 			game->tex[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red game->tex with black cross
// 			game->tex[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
// 			game->tex[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
// 			game->tex[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
// 			game->tex[4][texWidth * y + x] = 256 * xorcolor; //xor green
// 			game->tex[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
// 			game->tex[6][texWidth * y + x] = 65536 * ycolor; //red gradient
// 			game->tex[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
// 		}
// 	}
// }

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	printf("\nScreen size : %d x %d\n", game->screen_x, game->screen_y);
    // game->window_x = game->screen_x * 0.9;
    // game->window_y = game->screen_y * 0.9;
	game->window_x = TILE *40;
	game->window_y = TILE *30;
	// printf("wing x = %d\n", game->window_x);
	// printf("wing y = %d\n", game->window_y);
}

int	ft_create_window(t_game *game)
{
	initGameWindow(game);
	// generateTex(game);
	//import_textures(game);
	importTextures(game);
	getTextureAddress(game);
	mlx_loop_hook(game->mlx_ptr, renderNextFrame, game);
	mlx_key_hook(game->win_ptr, &hande_move, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	ft_putstr_fd("in create window\n", 1);
	return (1);
}
