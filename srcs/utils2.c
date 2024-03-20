#include "../includes/game.h"

bool	has_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (true);
		str++;
	}
	return (false);
}

bool red_gree_blue(char *str)
{
	int count;

	count = 0;
	while(count <=3)
	{
		if (*str && *str < '0' && *str > '9')
			return(false);
		while (*str && *str != '\n')
		{
			while(*str >= '0' && *str <= '9')
				str++;
			count += 1;
			if (*str == ',')
			{
				if (*(str + 1) >= '0' && *(str + 1) <= '9')
					count += 1;
			}
			str++;
		}
	}
	return (true);
}

bool	has_intruder(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else if (*str == ',')
			str++;
		else
		{
			ft_putchar_fd(*str, 1);
			ft_putchar_fd('\n', 1);
			return (true);
		}
	}
	return (false);
}

size_t	last_digit_position(char *line)
{
	int	i;

	i = ft_strlen(line);
	i -= 2;
	while (i && line[i] == ' ')
		i--;
	return (i);
}