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
	dprintf(1,"is floore ceiling ?\n");

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

	int f_flag;
	int	c_flag;

	f_flag = 0;
	c_flag = 0;

	f1 = 0;
	f2 = 0;
	game->mapLL = NULL;
	while (game->mapfile[game->pos])
	{
		// if ( )
		// {
		// 	ft_error("maps not last elem");
		// 	exit(EXIT_FAILURE);
		// }

		if (f1 == 4 && f2 == 2) //
			break ;
		dprintf(1,"pos = %d\n", game->pos);
		if (f2 == 2)
			ft_error("**********floor and ceiling are ok********* \n");
		while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
			game->pos++;
		if (game->mapfile[game->pos]
		&& is_floor_ceilnig_line(game->mapfile[game->pos]))
		{
			dprintf(1,"found FCline\n");
			check_floor_ceiling(game, &c_flag, &f_flag);
			f2++;
		}
		else if (game->mapfile[game->pos]
			&& is_direction_line(game->mapfile[game->pos]))
		{
			dprintf(1,"found texline\n");
			check_export_textures(game);
			f1++;
		}
		game->pos++;
		dprintf(1, "f1 = %d \n f2 = %d \n", f1, f2);
	}
	while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
		game->pos++;
	dprintf(1,"pos = %d\n", game->pos);	
	if (!game->mapfile[game->pos] || f1 != 4 || f2 != 2) // condition de check de doublons
	{
		dprintf(1, "ERROR POSITION 906\n");
		ft_error(NOT_IN_ORDER);
		free_part(game);
		exit(EXIT_FAILURE);
	}

	while (game->mapfile[game->pos])
	{
		dprintf(1,"pos = %d\n", game->pos);	
		dprintf(1,"line = [%s]\n", game->mapfile[game->pos]);	

		// if (game->mapfile[game->pos][0] == '\n')
		// {
		// 	ft_error("")
		// 	free_part(game);
		// 	exit (EXIT_FAILURE);
		// }
		if (!is_map(game, game->mapfile[game->pos])) // This line had been added to solve pb : (see. wrong_char_map2.cub)
		{
			ft_perror("here \n");
			dprintf(1, "ERROR POSITION 2222\n"); //Il a detecter le premier F 205... alors que cette partie devait etre traitee avant
			dprintf(1, "line[%s] from [%d]\n", game->mapfile[game->pos], game->pos);
			ft_perror(ERROR_NO_MATCH_CHAR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		if (game->mapfile[game->pos] && is_map(game,
				game->mapfile[game->pos]))
		{
			ft_perror("****here \n");

			// dprintf(1,"game->texfile = %s\n", game->texFiles[0]);	
			check_is_last_element(game);
			export_map(game);
		}
		else if (is_direction_line(game->mapfile[game->pos]) || is_floor_ceilnig_line(game->mapfile[game->pos]))
		{
			dprintf(1, "ERROR POSITION 5555\n");

			ft_perror(ERROR_NO_MATCH_CHAR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		if (game->mapfile[game->pos])
			game->pos++;
	}
	dprintf(1, "ERROR POSITION 4545\n");
	map_check_division(game);
}

