#include "../includes/game.h"

/*
    couleurs R,G,B range [0,255] : 0, 255, 255
            F 200,100,0
            C 225,30,0
*/
/*checks if the clors Format is valid
    a valid color format;
        has no spaces
        values are separated by a ,
        the are integers between
*/

bool	is_valid_rgb(char *RGB)
{
	if (has_spaces(RGB))
	{
		ft_error(ERROR_SPACE);
		return (false);
	}
	if (has_intruder(RGB))
	{
		dprintf(1, "ERROR POSITION 3333\n");
		ft_error(ERROR_NO_MATCH_CHAR);
		return (false);
	}
	if (!red_gree_blue(RGB))
	{
		ft_error("a shade is missing");
		return (false);
	}
	return (true);
}

int	affect_rgb(int *rgb, char *RGB, int *pos, char c)
{
	int		j;
	char	*color;

	if (RGB[*pos] == ',')
		((*pos)++);
	j = *pos;
	if (c == 'r' || c == 'g')
	{
		while (RGB[*pos] != ',')
			(*pos)++;
	}
	else
	{
		while (RGB[*pos])
			(*pos)++;
	}
	color = ft_substr(RGB, j, *pos - j + 1);
	*rgb = ft_atoi(color);
	if (*rgb > 255 || *rgb < 0)
	{
		ft_error("ERROR : RGB out of range!\n");
		free(color);
		return(1);
	}
	free(color);
	return(0);
}

void	affect_rgb_togame(t_game *game, t_color *rgb, char *RGB)
{
	int	i;

	i = 0;
	if (affect_rgb(&rgb->red, RGB, &i, 'r'))
	{
		free(RGB);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	if (affect_rgb(&rgb->green, RGB, &i, 'g'))
	{
		free(RGB);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	if (affect_rgb(&rgb->blue, RGB, &i, 'b'))
	{
		free(RGB);
		free_part(game);
		exit(EXIT_FAILURE);
	}
}

void	check_is_valid_rgb_format(t_game *game, char c)
{
	int		i;
	size_t	j;
	char	*rgb;

	rgb = NULL;
	i = 2;
	while (game->mapfile[game->pos][i]
		&& ft_isspace(game->mapfile[game->pos][i]))
		i++;
	j = last_digit_position(game->mapfile[game->pos]);
	rgb = ft_substr(game->mapfile[game->pos], i, j - i + 1);
	if (!is_valid_rgb(rgb))
	{
		free(rgb);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	if (c == 'F')
		affect_rgb_togame(game, &game->floor, rgb);
	else if (c == 'C')
		affect_rgb_togame(game, &game->ceiling, rgb);
	free(rgb);
}

void	check_floor_ceiling(t_game *game, int *c_flag, int	*f_flag)
{
	
		if (!ft_strncmp("F ", game->mapfile[game->pos], 2))
		{
			if (*f_flag)
			{
				ft_error("double floor found\n");
				free_part(game);
				exit(EXIT_FAILURE);
			}
			*f_flag = 1;//
			check_is_valid_rgb_format(game, 'F');
		}
		else if (!ft_strncmp("C ", game->mapfile[game->pos], 2))
		{
			if (*c_flag)
			{
				ft_error("double ceilning found\n");
				free_part(game);
				exit(EXIT_FAILURE);
			}
			*c_flag = 1;//
			check_is_valid_rgb_format(game, 'C');
		}
}
