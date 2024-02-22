#include "../includes/game.h"

static void EastOrWest(t_game *game, char dir)
{
    if (dir == 'E')
	{
		game->dirX = 0;
		game->dirY = -1;
		game->planeX = -0.7;
		game->planeY = 0;
	}
	else if (dir == 'W')
	{
		game->dirX = 0;
		game->dirY = 1;
		game->planeX = 0.7;
		game->planeY = 0;
	}
}



static void NorthOrSouth(t_game *game, char dir)
{
    if (dir == 'N')
	{
		game->dirX = 1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = -0.7;
	}
	else if (dir == 'S')
	{
		game->dirX = -1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = 0.7;
	}
}


void checkPlayerPos(t_game *game)
{
    int dirFound;
    int i;
    int j;

    dirFound = 0;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'E' || game->map[i][j] == 'W' )
            {
                dirFound += 1;
                EastOrWest(game, game->map[i][j]);
                NorthOrSouth(game, game->map[i][j]);
            }
            j++;
        }
        i++;
    }
    if (dirFound != 1)
    {
        ft_perror(ERROR_MULT_PLA_POS);
        //free
        exit (EXIT_SUCCESS);
    }
    dprintf(1, "pos = %f %f %f %f\n", game->dirX, game->dirY, game->planeX, game->planeY);
}
