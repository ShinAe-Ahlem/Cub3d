/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportMapElements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:19:39 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 14:28:00 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	export_map(t_game *game)
{
	t_list	*new;

	if (game->mapfile[game->pos])
	{
		new = ft_lstnew((char *)(game->mapfile[game->pos]));
		ft_lstadd_back(&(game->mapLL), new);
	}
}

void	define_maxmapwidth(t_game *game, int *i)
{
	if (game->maxMapWidth > (int)ft_strlen(game->map[*i]))
		game->maxMapWidth = game->maxMapWidth;
	else
		game->maxMapWidth = (int)ft_strlen(game->map[*i]);
}

void	ll_toarray_converter(t_game *game)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	temp = game->mapLL;
	temp2 = game->mapLL;
	game->mapCharHeight = 0;
	i = 0;
	game->map = NULL;
	while (temp != NULL)
	{
		temp = temp->next;
		game->mapCharHeight++;
	}
	game->map = (char **)malloc((game->mapCharHeight + 1) * sizeof(char *));
	if (!(game->map))
		return ;
	while (temp2 != NULL)
	{
		game->map[i] = ft_strdup(temp2->content);
		define_maxmapwidth(game, &i);
		i++;
		temp2 = temp2->next;
	}
	game->map[i] = 0;
}
