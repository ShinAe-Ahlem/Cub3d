/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:08:02 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 16:07:03 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_table(char **tab)
{
	int	i;

	if (tab)
	{
		if (*tab)
		{
			i = 0;
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
