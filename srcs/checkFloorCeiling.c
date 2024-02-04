


#include "../includes/game.h"

/*

    couleurs R,G,B range [0,255] : 0, 255, 255

    
            F 200,100,0
            C 225,30,0
*/



/*checks if the clors Format is valid
    a valid color format;
        has no spaces
        values are separated by a ,
        the are integers between

*/

bool hasSpaces(char *str)
{
    while(*str)
    {
        if (*str == ' ')
            return(true);
        str++;
    }
    return(false);
}

bool hasIntruder(char *str)
{
    while(*str && *str != '\n')     
    {
       if(*str >= '0' && *str <= '9')
            str++;
        else if (*str == ',')
            str++;
        else
        {
            ft_putchar_fd(*str, 1);
            ft_putchar_fd('\n', 1);
            return(true);
        }
    }
    return(false);
}

bool isValidRGB(char *RGB)
{
    if (hasSpaces(RGB))
    {
        ft_error(ERROR_SPACE);
        return(false);
    }
    if (hasIntruder(RGB))
    {
        ft_error(ERROR_NO_MATCH_CHAR);
        return(false);
    }
    return(true);
}

size_t lastDigitPosition(char *line)
{
    int i;
    i = ft_strlen(line);
    i -= 2; /*skip '\n' && \0*/
    while(i && line[i] == ' ')
        i--;
    return(i);
}

void affectRGB(int *rgb, char *RGB, int *pos, char c)
{
    int j;
    char *color;
    if (RGB[*pos] == ',')
        ((*pos)++);
    j = *pos;
    if(c == 'r' || c== 'g' )
    {
        while(RGB[*pos] != ',')
            (*pos)++;
    }
    else
    {
        while(RGB[*pos])
            (*pos)++;
    }
    color = ft_substr(RGB,j , *pos - j + 1);
    *rgb = ft_atoi(color);
    if (*rgb > 255 || *rgb < 0)
    {
        ft_error("ERROR : RGB out of range!\n");
        /*free*/
        exit(EXIT_FAILURE);
    }
    free(color);
}

void affectRGBtoGame(t_color *rgb, char *RGB)
{
    int i;

    i = 0;
    affectRGB(&rgb->red, RGB, &i, 'r');
    affectRGB(&rgb->green, RGB, &i, 'g');
    affectRGB(&rgb->blue, RGB, &i, 'b');
}

void CheckIsValidFormat(t_game *game, char c)
{
    int i;
    size_t j;
    char *RGB;
    RGB = NULL;
    i = 2; /*"Already checked the first two caracters"*/
    while (game->mapfile[game->pos][i] && ft_isspace(game->mapfile[game->pos][i]))
            i++;
    /*delimit RGB*/
    j = lastDigitPosition(game->mapfile[game->pos]);
    /*substruct RGB*/
    RGB = ft_substr(game->mapfile[game->pos], i, j - i + 1);
    if(!isValidRGB(RGB))
    {
        free(RGB);
        /*free*/
        ft_error("Invalid RGB format\n");
        exit(EXIT_FAILURE);
    }
    /*convert RGB to integers and affect them to game*/
    /*RGB now is 200,100,0*/
    if (c == 'F')
        affectRGBtoGame(&game->floor, RGB);
    else
        affectRGBtoGame(&game->ceiling, RGB);
    free(RGB);
}


void checkFloorCeiling(t_game *game)
{
    int F_flag = 0;
    int C_flag = 0;
    int i;
    i = game->pos;
    while(game->mapfile[game->pos] != NULL)
    {
        if (game->mapfile[game->pos][0] == '\n')
        {
            ft_error("Enter found\n");
            break ;
        }
        if (!ft_strncmp("F ", game->mapfile[game->pos], 2))
        {
            if(F_flag)
            {
                printf("double floor found\n");
                /*free game*/
                exit(EXIT_FAILURE);
            }
            F_flag = 1;
            CheckIsValidFormat(game, 'F');
            ft_putstr_fd("floor found\n", 1);

        }
        else if (!ft_strncmp("C ", game->mapfile[game->pos], 2))
        {
            if(C_flag)
            {
                ft_error("double ceilning found\n");
                /*free game*/
                exit(EXIT_FAILURE);
            }
            C_flag = 1;
            CheckIsValidFormat(game, 'C');
            ft_putstr_fd("ceiling found\n", 1);
        }
        game->pos++;
    }
}

