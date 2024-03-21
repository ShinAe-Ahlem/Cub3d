#include "../includes/game.h"

static bool	is_direction_line(char *line)
{
	dprintf(1,"is direction line ?\n");
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
	int f1;
	int f2;

	f1 = 0;
	f2 = 0;
	game->mapLL = NULL;
	while (game->mapfile[game->pos] || !f1 || !f2)
	{
		dprintf(1,"pos = %d\n", game->pos);
		if (f1 && f2)
			break;
		while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
			game->pos++;
		if (game->mapfile[game->pos]
			&& is_direction_line(game->mapfile[game->pos]))
		{
			dprintf(1,"found texline\n");
			check_export_textures(game);
			f1 = 1;
		}
		else if (game->mapfile[game->pos]
		&& is_floor_ceilnig_line(game->mapfile[game->pos]))
		{
			dprintf(1,"found FCline\n");
			check_floor_ceiling(game);
			f2 = 1;
		}
		dprintf(1, "f1 = %d \n f2 = %d \n", f1, f2);
		game->pos++;
	}
	while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
		game->pos++;
	while (game->mapfile[game->pos])
	{
		// if (game->mapfile[game->pos][0] == '\n')
		// {
		// 	ft_error("")
		// 	free_part(game);
		// 	exit (EXIT_FAILURE);
		// }
		dprintf(1,"here\n");
		if (game->mapfile[game->pos] && is_map(game,
				game->mapfile[game->pos]))
		{
			// dprintf(1,"game->texfile = %s\n", game->texFiles[0]);	
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

