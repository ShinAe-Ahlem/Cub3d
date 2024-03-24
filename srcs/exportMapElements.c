/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportMapElements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:36:15 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 17:29:12 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	export_map(t_game *game)
{
	t_list	*new;

	if (game->mapfile[game->pos])
	{
		new = ft_lstnew((char *)(game->mapfile[game->pos]));
		ft_lstadd_back(&(game->map_ll), new);
	}
}

void	define_maxmapwidth(t_game *game, int *i)
{
	if (game->max_map_width > (int)ft_strlen(game->map[*i]))
		game->max_map_width = game->max_map_width;
	else
		game->max_map_width = (int)ft_strlen(game->map[*i]);
}

void	ll_toarray_converter(t_game *game)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	temp = game->map_ll;
	temp2 = game->map_ll;
	game->map_char_height = 0;
	i = 0;
	game->map = NULL;
	while (temp != NULL)
	{
		temp = temp->next;
		game->map_char_height++;
	}
	game->map = (char **)malloc((game->map_char_height + 1) * sizeof(char *));
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
