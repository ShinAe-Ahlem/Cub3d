#include "../includes/game.h"

void	FC_init(t_game *game)
{
	game->floor.red = 0;
	game->floor.green = 0;
	game->floor.blue = 0;
	game->ceiling.red = 0;
	game->ceiling.green = 0;
	game->ceiling.blue = 0;
}

void	mapInfoInit(t_game *game)
{
	game->mapfile = NULL;
	game->mapLL = NULL;
	game->map = NULL;
	game->mapCharHeight = 0;
	game->maxMapWidth = 0;
	game->playerPos = (t_coord *)malloc(sizeof(t_coord));
	if (game->playerPos == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->playerPos->x = 0;
	game->playerPos->y = 0;
	game->playerPosDelta = (t_coord *)malloc(sizeof(t_coord));
	if (game->playerPosDelta == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->playerPosDelta->x = 0;
	game->playerPosDelta->y = 0;
	game->playerAngle = 0;
}

void	initGameParam(t_game *game)
{
	game->game_name = "Alhem and Shin Ae's World <3";
	game->fd = 0;
	game->pos = 0;
	game->x = 0;
	game->y = 0;
	game->mlx_ptr = NULL;
	game->tex = NULL;
	game->map = NULL;
	game->mapfile = NULL;
	game->texFiles = NULL;
	game->texLines = NULL;
	FC_init(game);
	mapInfoInit(game);
}