#include "../includes/game.h"

void	check_nb_arg(int ac)
{
	if (ac != 2)
	{
		ft_error(ERROR_NB_ARG);
		exit(EXIT_FAILURE);
	}
}

void	check_arg(int ac, char **av)
{
	check_nb_arg(ac);
	(void)av;
}
