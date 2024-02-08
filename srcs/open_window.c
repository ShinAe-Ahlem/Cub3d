#include "../includes/game.h"

void init_player(t_game *game)
{
	game->player = malloc(1 * sizeof(t_player));
    game->player->px = 10;
    game->player->py = 10;
}

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	printf("\nScreen size : %d x %d\n", game->screen_x, game->screen_y);
    // game->window_x = game->screen_x * 0.9;
    // game->window_y = game->screen_y * 0.9;
	game->window_x = TILE *40;
	game->window_y = TILE *30;
	printf("wing x = %d\n", game->window_x);
	printf("wing y = %d\n", game->window_y);
}

int	ft_create_window(t_game *game)
{
	initGame(game);
	init_player(game);
	import_textures(game);
	// drawFloorCeiling(game);
	renderGame(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_key_hook(game->win_ptr, &hande_move, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}
