#include "../includes/game.h"

void	print_tlist(t_list *list)
{
	t_list	*copy;

	copy = list;
	dprintf(1, "****************print tlist starts:*************\n");
	while (copy != NULL)
	{
		dprintf(1, "%s", (char *)(copy->content));
		copy = copy->next;
	}
}

void	temp_length_set(char **temp, const char *str, int *length)
{
	*temp = ft_strtrim(str, " \n");
	*length = ft_strlen(*temp);
}

bool	charset_finder(const char *charset, const char *str)
{
	int		i;
	int		j;
	int		length;
	char	*temp;

	i = 0;
	temp_length_set(&temp, str, &length);
	while (temp[i] && length)
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == temp[i])
			{
				length--;
				break ;
			}
			j++;
		}
		i++;
	}
	free(temp);
	if (length == 0)
		return (1);
	return (0);
}
