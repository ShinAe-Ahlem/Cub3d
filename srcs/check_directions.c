#include "../includes/game.h"

static bool	NO = 0;
static bool	SO = 0;
static bool	WE = 0;
static bool	EA = 0;

int	directionExist(char *direction, char *line, bool *exist)
{
	// printf("exist = %d\n", *exist);
	if (!ft_strncmp(direction, line, 3))
	{
		if (!(*exist))
		{
			*exist = 1;
			printf("%s FOUND\n", direction);
			return (0);
		}
		else 
		{
			ft_error("Invalid map (double attribution of texture)");
			return (1);
		}
	}
	return (1);
}

bool	checkDirection(char *line)
{
	// static bool	NO;
	// static bool	SO;
	// static bool	WE;
	// static bool	EA;


	printf("\nno = %d, so = %d, we = %d, ea= %d\n", NO, SO, WE, EA);
	printf("line = %s\n", line);
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3) || !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3))
	{
		if (!directionExist("NO", line, &NO) || !directionExist("SO", line, &SO)
			|| !!directionExist("EA", line, &EA) || !directionExist("WE", line, &WE))
			return(0);
	}
	ft_error("Invalid map (Unknown direction)");
	return (1);

}

