#include "../includes/game.h"

typedef struct s_direction
{
	int	NO;
	int	SO;
	int	EA;
	int	WE;
}			t_direction;

void	DirectionAlreadySeen(t_direction *direction, char *line)
{
	if (ft_strncmp("NO ", line, 3))
	{
		direction->NO += 1;
	}	
	else if (ft_strncmp("SO ", line, 3))
	{
		direction->SO += 1;
	}
	else if (ft_strncmp("EA ", line, 3))
	{
		direction->EA += 1;
	}
	else if (ft_strncmp("WE ", line, 3))
	{
		direction->WE += 1;
	}
}

void	direction_init(t_direction *direction)
{
	direction->NO = 0;
	direction->SO = 0;
	direction->EA = 0;
	direction->WE = 0;
}

bool	checkDirection(char *line)
{
	t_direction	direction;

	direction_init(&direction);
	DirectionAlreadySeen(&direction, line);
	if (direction.NO > 1 || direction.SO > 1 || direction.EA > 1 || direction.WE > 1)
		return (1);
	return (0);
	
}
