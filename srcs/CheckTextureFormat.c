#include "../includes/game.h"

bool	has_valid_extension(char *line)
{
	int	i;

	i = ft_strlen(line) - 2;
	if (line[i] == 'm' && line[i - 1] == 'p' && line[i - 2] == 'x' && line[i
		- 3] == '.')
		return (1);
	return (0);
}

static bool	has_valid_prefix(char *texture)
{
	if (!ft_strncmp("NO ", texture, 3))
		return (true);
	else if (!ft_strncmp("SO ", texture, 3))
		return (true);
	else if (!ft_strncmp("WE ", texture, 3))
		return (true);
	else if (!ft_strncmp("EA ", texture, 3))
		return (true);
	ft_error("not valid prefix\n");
	return (false);
}

bool	are_valid_texture_formats(t_game *game)
{
	int	i;

	i = game->pos;
	while (i < game->pos + 4)
	{
		if (game->mapfile[i][0] == '\n')
		{
			ft_error("found empty line or format is invalid");
			return (false);
		}
		if (!has_valid_prefix(game->mapfile[i]))
			return (false);
		if (!has_valid_extension(game->mapfile[i]))
		{
			ft_error("not a valid extension\n");
			return (false);
		}
		i++;
	}
	return (true);
}