#include "../includes/game.h"

static bool	is_direction_line(char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		return (true);
	else if (!ft_strncmp("SO ", line, 3))
		return (true);
	else if (!ft_strncmp("WE ", line, 3))
		return (true);
	else if (!ft_strncmp("EA ", line, 3))
		return (true);
	return (false);
}

static bool	is_floor_ceilnig_line(char *line)
{

	if (!ft_strncmp("F ", line, 2))
		return (true);
	if (!ft_strncmp("C ", line, 2))
		return (true);
	return (false);
}

static bool	is_map(t_game *game, char *line)
{
	char    charset[8] = "01NSEW ";
	(void)game;
	if (charset_finder(charset, line))
		return (true);
	return(false);
}

void	check_map_elements(t_game *game)
{
	game->pos = 0;
	int c_flag;
	int f_flag;

	c_flag = 0;
	f_flag = 0;
	game->mapLL = NULL;
	while (game->mapfile[game->pos])
	{
		while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
			game->pos++;
		if (game->mapfile[game->pos]
		&& is_floor_ceilnig_line(game->mapfile[game->pos]))
		{
			check_floor_ceiling(game, &c_flag, &f_flag);
			// f_flag++;
		}
		else if (game->mapfile[game->pos]
			&& is_direction_line(game->mapfile[game->pos]))
		{
			check_export_textures(game);
			// c_flag++;
		}
		game->pos++;

	}
	while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
		game->pos++;
	if (!game->mapfile[game->pos])
	{
		ft_error(NOT_IN_ORDER);
		free_part(game);
		exit(EXIT_FAILURE);
	}

	while (game->mapfile[game->pos])
	{
		if (!is_map(game, game->mapfile[game->pos])) // This line had been added to solve pb : (see. wrong_char_map2.cub)
		{
			ft_perror(ERROR_NO_MATCH_CHAR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		if (game->mapfile[game->pos] && is_map(game,
				game->mapfile[game->pos]))
		{	
			check_is_last_element(game);
			export_map(game);
		}
		else if (is_direction_line(game->mapfile[game->pos]) || is_floor_ceilnig_line(game->mapfile[game->pos]))
		{
			ft_perror(ERROR_NO_MATCH_CHAR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		if (game->mapfile[game->pos])
			game->pos++;
	}
	map_check_division(game);
}

