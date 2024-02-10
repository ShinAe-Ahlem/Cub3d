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
    char    *temp;

    i = 0;
    temp = ft_strtrim(str, " \n");
    length = ft_strlen(temp);
    while (temp[i] && length)
    {
        j = 0;
        while (charset[j])
        {
            if (charset[j] == temp[i])
            {
                // printf("matched charset[j]: %c, str[i] : %c\n", charset[j], str[i]);
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

float angleToRadian (float angle)
{
    float radian;

    radian = angle *(PI / 180);
    return (radian);
}

float RadianToAngle (float radian)
{
    float angle;

    angle = radian * (180 / PI);
    return (angle);
}
