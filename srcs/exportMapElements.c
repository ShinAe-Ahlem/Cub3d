/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportMapElements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:52:58 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:53:46 by anouri           ###   ########.fr       */
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
		game->max_map_width = game->max_map_width > (int)ft_strlen(game->map[i]) ? game->max_map_width : (int)ft_strlen(game->map[i]);
		i++;
		temp2 = temp2->next;
	}
	game->map[i] = 0;
}
