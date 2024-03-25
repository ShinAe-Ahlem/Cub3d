/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:10:05 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 11:26:48 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_table(char **tab)
{
	int	row;

	row = 0;
	if (tab)
	{
		while (tab[row])
		{
			dprintf(1, "tab[%d]:", row);
			ft_putstr_fd(tab[row], 1);
			dprintf(1, "\n");
			row++;
		}
	}
}
