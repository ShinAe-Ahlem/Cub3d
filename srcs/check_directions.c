#include "../includes/game.h"

int	directionExist(char *direction, char *line, bool exist)
{
	if (!ft_strncmp(direction, line, 3))
	{
		if (exist)
		{
			ft_error("Invalid map (double attribution of texture)");
			return (1);
		}
		exist = 1;
		printf("%s FOUND\n", direction);
		return (0);
	}
	return (0);
}

bool	checkDirection(char *line)
{
	static bool	NO;
	static bool	SO;
	static bool	WE;
	static bool	EA;

	NO = 0;
	SO = 0;
	WE = 0;
	EA = 0;
	if (!directionExist("NO", line, NO) && !directionExist("SO", line, SO)
		&& !directionExist("EA", line, EA) && !directionExist("WE", line, WE))
		return (0);
	else
	{
		ft_error("Invalid map (Unknown direction)");
		return (1);
	}
	return (0);
}
