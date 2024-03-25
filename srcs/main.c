/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:37:48 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/25 15:51:45 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	main(int ac, char **av, char **env)
{
	t_game	game;

	check_arg(ac, av);
	check_env(env);
	init_game_param(&game);
	game.mapfile = ft_read_map(av[1]);
	if (!game.mapfile)
	{
		ft_error("ERROR : file is empty");
		return (1);
	}
	check_map_elements(&game);
	ft_create_window(&game);
	return (0);
}
