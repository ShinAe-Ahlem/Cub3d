#include "../includes/game.h"

static void	importTextures(t_game *game)
{
	int	size;

	dprintf(1,"\n\n\n\n\n\n\n\n\n\n\ngame->no = %s \n\n\n\n\n\n\n\n\n\n\n", game->texture->NO);

	game->tex =(void **) malloc(5 * sizeof(void *));
	if (!game->tex)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	dprintf(1,"\ntex = %s\n", game->texture->NO);
	game->tex[0] = mlx_xpm_file_to_image(game->mlx_ptr,game->texFiles[0],
			&size, &size);
	dprintf(1, "tex[0] = %p\n", game->tex[0]);
	// dprintf(1, "north\n");
	game->tex[1] = mlx_xpm_file_to_image(game->mlx_ptr, game->texFiles[1],
			&size, &size);
	// dprintf(1, "east\n");
	game->tex[3] = mlx_xpm_file_to_image(game->mlx_ptr, game->texFiles[3],
			&size, &size);
	game->tex[2] = mlx_xpm_file_to_image(game->mlx_ptr, game->texFiles[2],
	// dprintf(1, "south\n");
			&size, &size);
	// dprintf(1, "west\n");
	game->tex[4] = NULL;
	// dprintf(1, "null\n");
}

static void	getTextureAddress(t_game *game)
{
	dprintf(1,"\nget texture address\n");
	game->texAddress = (int **)malloc(5 * sizeof(int *));
	if (!game->texAddress)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while(i++ < 4)
	{
		dprintf(1,"\ntex[%d] = %p\n", i, game->tex[i]);
	}
	game->texAddress[0] = (int *)mlx_get_data_addr(game->tex[0], &game->bpp[0],
			&game->line_len[0], &game->endian[0]);
	dprintf(1, "************\n\n\n\n\ntextadd= %p***********************************\n", game->texAddress[0]);
	game->texAddress[1] = (int *)mlx_get_data_addr(game->tex[1], &game->bpp[1],
			&game->line_len[1], &game->endian[1]);
	dprintf(1, "%p\n", game->texAddress[1]);
	game->texAddress[2] = (int *)mlx_get_data_addr(game->tex[2], &game->bpp[2],
			&game->line_len[2], &game->endian[2]);
	dprintf(1, "%p\n", game->texAddress[2]);
	game->texAddress[3] = (int *)mlx_get_data_addr(game->tex[3], &game->bpp[3],
			&game->line_len[3], &game->endian[3]);
	dprintf(1, "%p\n", game->texAddress[3]);
	game->texAddress[4] = NULL;
}

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	game->window_x = TILE * 40;
	game->window_y = TILE * 30;
}


// static void generateTextures(t_game *game)
// {
// 	game->texg = malloc(4 * sizeof(int *));

// 	//generate some textures
// 	for(int x = 0; x < texWidth; x++)
// 	for(int y = 0; y < texHeight; y++)
// 	{
// 		int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
// 		//int xcolor = x * 256 / texWidth;
// 		// int ycolor = y * 256 / texHeight;
// 		int xycolor = y * 128 / texHeight + x * 128 / texWidth;
// 		game->texg[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red game->tex with black cross
// 		game->texg[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscaleg
// 		game->texg[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
// 		game->texg[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
// 	}
// }  

int	ft_create_window(t_game *game)
{
	initGameWindow(game);
	importTextures(game);
	getTextureAddress(game);
	// generateTextures(game);
	mlx_key_hook(game->win_ptr, &handle_move, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop_hook(game->mlx_ptr, renderNextFrame, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
