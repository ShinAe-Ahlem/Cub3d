
#include "../includes/game.h"

void	zeroThisLine(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == '0')
		{
			ft_perror(ERROR_MAP_UNCLOSED);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	zeroSideBlank(t_game *game, char *line)
{
	int		len;
	char	*temp;

	temp = ft_strtrim(line, " \n");
	len = ft_strlen(temp) - 1;
	if (len > 0 && (temp[len] == '0' || temp[0] == '0'))
	{
		ft_perror(ERROR_MAP_UNCLOSED);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	free(temp);
}

void	zeroExposed(t_game *game, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0')
		{
			if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j])
				|| !(map[i - 1][j]) || !(map[i + 1][j]) || ft_isspace(map[i][j
					- 1]) || ft_isspace(map[i][j + 1]) || !(map[i][j - 1]
					|| !(map[i][j + 1])))
			{
				ft_perror(ERROR_MAP_UNCLOSED);
				free_part(game);
				exit(EXIT_FAILURE);
			}
		}
		j++;
	}
}

void	zero_blank_contact(t_game *game)
{
	int	i;

	i = 0;
	zeroThisLine(game, 0);
	// print_char_table(game->map);
	while (game->map[i])
	{
		zeroSideBlank(game, game->map[i]);
		zeroExposed(game, game->map, i);
		i++;
	}
	i -= 1;
	zeroThisLine(game, i);
}
