#include "../includes/game.h"

int	main(int ac, char **av, char **env)
{
	t_game	game;

	// 1) init
	// 2) parsing (argument check, lecture cartte, map validity check)
	// 3) free / destroy
	check_arg(ac, av);
	check_env(env);
	initGameParam(&game);
	game.mapfile = ft_read_map(av[1]);
	if (!game.mapfile) // not sure about this 
	{
		ft_error("ERROR : file is empty");
		return (1);
	}
	check_map_elements(&game);
	printf("\n before create window\n");
	ft_create_window(&game);
	return(0);
}
