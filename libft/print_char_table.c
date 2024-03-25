/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:10:05 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 09:46:16 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_table(char **tab) 
{
	int row;

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

// void	print_char_table(char **tab)  //Archive
// {
// 	int row;

// 	row = 0;
// 	if (tab)
// 	{
// 		while (*tab)
// 		{
// 			dprintf(1, "tab[%d]:", row);
// 			ft_putstr_fd(*tab++, 1);
// 			dprintf(1, "\n");
// 			row++;
// 		}
// 	}
// }


