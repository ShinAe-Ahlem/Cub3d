#include "../includes/game.h"

void freeCharArray(char ***array)
{
    int i = 0;

    while ((*array)[i] != NULL)
    {
        free((*array)[i]);
        i++;
    }
    free(*array);
    *array = NULL;
}

