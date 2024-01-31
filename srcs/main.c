/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:04:33 by anouri            #+#    #+#             */
/*   Updated: 2024/01/31 10:29:51 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

int	render(t_data *data)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (data->win_ptr != NULL)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
    return (0);
}

int	main(int ac, char **av, char **env)
{
    // t_game	game;

    // 1) init
    // 2) parsing (argument check, lecture cartte, map validity check)
    // 3) free / destroy

    check_arg(ac, av);
    check_env(env);

    // ft_create_window(&game);
    char **map_lines = ft_read_map(av[1]);
    if (map_lines)
        print_char_table(map_lines);

    /* we will exit the loop if there's no window left, and execute this code */
    // mlx_destroy_display(game.mlx_ptr);
    // free(game.mlx_ptr);
}
