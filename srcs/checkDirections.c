/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkDirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:54 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:21:55 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

typedef struct s_direction
{
	int	no;
	int	so;
	int	ea;
	int	we;
}		t_direction;

static void	direction_already_seen(t_direction *direction, char *line)
{
	if (ft_strncmp("no ", line, 3))
	{
		direction->no += 1;
	}
	else if (ft_strncmp("so ", line, 3))
	{
		direction->so += 1;
	}
	else if (ft_strncmp("ea ", line, 3))
	{
		direction->ea += 1;
	}
	else if (ft_strncmp("we ", line, 3))
	{
		direction->we += 1;
	}
}

void	direction_init(t_direction *direction)
{
	direction->no = 0;
	direction->so = 0;
	direction->ea = 0;
	direction->we = 0;
}

bool	checkdirection(char *line)
{
	t_direction	direction;

	direction_init(&direction);
	direction_already_seen(&direction, line);
	if (direction.no > 1 || direction.so > 1 || direction.ea > 1
		|| direction.we > 1)
		return (1);
	return (0);
}
