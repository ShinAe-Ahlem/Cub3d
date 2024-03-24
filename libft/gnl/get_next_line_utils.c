/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:11:28 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 16:07:50 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	size_t	i;
	size_t	size;
	char	*res;

	size = ft_strlengnl(s1) + ft_strlengnl(s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (i < ft_strlengnl(s1) || i < ft_strlengnl(s2))
	{
		if (i < ft_strlengnl(s1))
			res[i] = s1[i];
		if (i < ft_strlengnl(s2))
			res[i + ft_strlengnl(s1)] = s2[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}
