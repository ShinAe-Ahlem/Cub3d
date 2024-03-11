#include "../includes/game.h"


void graphique_init(t_game *game)
{
	game->grp = (t_grp *)malloc(sizeof(t_grp));
    if (game->grp == NULL)
	{
        ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
    }
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
	game->texture = NULL;
	// game->texture->NO = NULL;
	// game->texture->SO = NULL;
	// game->texture->EA = NULL;
	// game->texture->WE = NULL;
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

void initGameParam(t_game *game)
{
	game->fd = 0;
	game->pos = 0;
	game->x = 0;
	game->y = 0;
	game->mlx_ptr = NULL;
	graphique_init(game);
	texture_init(game);
	FC_init(game);
	mapInfoInit(game);
	game->direction = malloc(1 * sizeof(t_coord));
	if (!game->direction)
	{
		perror("malloc\n");
		exit(EXIT_FAILURE);
	}
	game->cameraPlane = malloc(1 * sizeof(t_coord));
	if (!game->cameraPlane)
	{
		perror("malloc\n");
		exit(EXIT_FAILURE);
	}
	game->direction->x = -1;//initial direction vector
	game->direction->y = 0; //initial direction vector
	game->cameraPlane->x = 0;
	game->cameraPlane->y = 1;
}