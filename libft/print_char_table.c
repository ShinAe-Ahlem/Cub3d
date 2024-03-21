/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:10:05 by anouri            #+#    #+#             */
/*   Updated: 2024/03/20 15:16:39 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_table(char **tab)
{
	// ft_putstr_fd("\n",1);
	if (tab)
	{
		while (*tab)
			ft_putstr_fd(*tab++, 1);
			// printf("%s", *tab++);
		// ft_putstr_fd("\n----------------------- seperation end of map ---------------------\n\n", 1);
	}
	// ft_putstr_fd("\n",1);
}
