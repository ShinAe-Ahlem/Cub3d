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
		game->maxMapWidth = game->maxMapWidth > (int)ft_strlen(game->map[i]) ? game->maxMapWidth : (int)ft_strlen(game->map[i]);
		i++;
		temp2 = temp2->next;
	}
	game->map[i] = 0;
}
