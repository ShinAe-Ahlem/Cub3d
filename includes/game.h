/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:06:43 by shikwon           #+#    #+#             */
/*   Updated: 2024/01/27 18:12:30 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_grp // grqphique
{
    void    *north;
    void    *south;
    void    *east;
    void    *west;
    // void    *floor;
    // void    *ceiling;
    // void    *item;
    // void    *door;
    // void    *ennemi_one;
    // void    *ennemi_two;
}   t_grp;


typedef struct s_game
{
    int fd; // fd of map we read with gnl
    void    *mlx_ptr;
    t_grp   grp;
    void	*win_ptr;
    
}   t_game;


#endif