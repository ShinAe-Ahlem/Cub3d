#include "../includes/game.h"

/*check ft_isspace in libft => tried and it didn't work! try again!*/

bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' || *line != '\n' || *line != '\t')
			return (false);
		line++;
	}
	return (true);
}

void	check_has_spaces(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		if (!game->map[i + 1])
			return ;
		j = 0;
		while (game->map[i][j])
		{
			if (ft_isspace(game->map[i][j]))
			{
				while (ft_isspace(game->map[i][j]))
					j++;
				if (game->map[i][j] != '\n')
				{
					ft_error("found empty line\n");
					exit(EXIT_FAILURE);
				}
			}
			else
				j++;
		}
		i++;
	}
}
