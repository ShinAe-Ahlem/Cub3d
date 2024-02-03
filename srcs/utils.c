#include "../includes/game.h"

void    print_tlist(t_list *list)
{
    t_list *copy = list;
    
    printf("print tlist starts:\n");
    while (copy != NULL)
    {
        printf("%s", (char *)(copy->content));
        copy = copy->next;
    }
}

bool charset_finder(const char *charset, const char *str)
{
    int i;
    int j;
    int length;

    i = 0;
    length = ft_strlen(str) - 1;
    while (str[i])
    {
        j = 0;
        while (charset[j])
        {
            if (charset[j] == str[i])
            {
                length--;
                break ;
            }
            j++;
        }
        i++;
    }
    if (length == 0)
        return (1);
    return (0);
}
