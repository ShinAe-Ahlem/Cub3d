/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:10:57 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 12:12:37 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd, int error);
char	*ft_strjoinGNL(char *str1, char *str2);
size_t	ft_strlenGNL(char *s);

#endif
