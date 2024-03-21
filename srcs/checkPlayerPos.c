#include "../includes/game.h"

static void	east_or_west(t_game *game, char dir)
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

static void	north_or_south(t_game *game, char dir)
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

void	check_player_pos(t_game *game)
{
	int	dir_found;
	int	i;
	int	j;

	dir_found = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				dir_found += 1;
				east_or_west(game, game->map[i][j]);
				north_or_south(game, game->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (dir_found != 1)
	{
		ft_perror(ERROR_MULT_PLA_POS);
		free_part(game);
		exit(EXIT_SUCCESS);
	}
}
