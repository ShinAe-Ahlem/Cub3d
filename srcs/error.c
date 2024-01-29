#include "../includes/game.h"



void    ft_error(char *code_error)
{
    write (2, code_error,ft_strlen(code_error));
    write(2, "\n", 1);
}
