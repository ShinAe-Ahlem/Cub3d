/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroBlankContact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:25:57 by shikwon           #+#    #+#             */
/*   Updated: 2024/02/04 18:08:23 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void    zeroThisLine(t_game *game, int i)
{
    int j;

    j = 0;
    while (game->map[i][j])
    {
        if (game->map[i][j] == '0')
        {
            ft_perror(ERROR_MAP_UNCLOSED);
            //freethis
            exit(EXIT_FAILURE);
        }
        j++;
    }
}

void    zeroSideBlank(char *line)
{
    int len;
    char *temp;

    temp = ft_strtrim(line, " \n");
    // printf("line : [%s]\n", line);
    len = ft_strlen(temp) - 1;
    // printf("temp : [%s]\n", temp);
    // printf("[%c]\n", line[len]);
    if (temp[len] == '0' || temp[0] == '0')
    {
        ft_perror(ERROR_MAP_UNCLOSED);
        //freethis
        exit(EXIT_FAILURE);
    }
    free(temp);
}

void    zeroExposed(char **map, int i)
{
    int j;

    j = 0;

    while (map[i][j])
    {
        if (map[i][j] == '0')
        {
            if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j]) || !(map[i - 1][j]) || !(map[i + 1][j]))
            {
                printf("Opened Zero found!!!\n\n\n");
                ft_perror(ERROR_MAP_UNCLOSED);
                //freethis
                exit (EXIT_FAILURE);
            }
        }
        j++;
    }
}

void	zeroBlankContact(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
    // printf("insideZBC1\n");
    print_char_table(game->map);
    zeroThisLine(game, 0);
	while (game->map[i])
	{
		j = 0;
        // printf("insideZBC2 - map[%d]\n", i);
        zeroSideBlank(game->map[i]);
        zeroExposed(game->map, i);
		i++;
	}
    i -= 1;
    zeroThisLine(game, i);
}
