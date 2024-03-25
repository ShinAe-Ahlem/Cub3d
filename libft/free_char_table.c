/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:08:02 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 10:45:34 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	free_table(char **tab) // if pb occurs, return to archived version
// {
	
// 	int	i;

// 	if (tab)
// 	{
// 		i = 0;
// 		while (tab[i])
// 		{
// 			free(tab[i]);
// 			tab[i] = NULL;
// 			i++;
// 		}
// 		free(tab);
// 		tab = NULL;
// 	}
// }

void	free_table(char **tab) // ARCHIVE
{
	int	i;

	i = 0;
	if (tab)
	{
		if (*tab)
		{
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
		}
		free(tab);
	}
	tab = NULL;
}
