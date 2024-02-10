#include "../includes/game.h"


void graphique_init(t_game *game)
{
	game->grp->east = NULL;
	game->grp->west = NULL;
	game->grp->south = NULL;
	game->grp->north = NULL;
	game->grp->floor = NULL;
	game->grp->wall = NULL;
	game->grp->ennemi_one = NULL;
}

void texture_init(t_game *game)
{
	game->texture.NO = NULL;
	game->texture.SO = NULL;
	game->texture.EA = NULL;
	game->texture.WE = NULL;
}

void FC_init(t_game *game)
{
	game->floor.red = 0;
	game->floor.green = 0;
	game->floor.blue = 0;
	game->ceiling.red = 0;
	game->ceiling.green = 0;
	game->ceiling.blue = 0;
}

void mapInfoInit(t_game *game)
{
	game->mapfile = NULL;
	game->mapLL = NULL;
	game->map = NULL;
	game->mapCharHeight = 0;
	game->playerPos->x = 0;
	game->playerPos->y = 0;
}

void initGameParam(t_game *game)
{
	game->fd = 0;
	game->pos = 0;
	game->x = 0;
	game->y = 0;
	graphique_init(game);
	texture_init(game);
	FC_init(game);
	mapInfoInit(game);
	initGameWindow(game);
}