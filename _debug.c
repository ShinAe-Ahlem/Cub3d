# include <stdbool.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

bool charset_finder(const char *charset, const char *str)
{
    int i;
    int j;
    int length;

    i = 0;
    length = strlen(str);
    printf("%d\n", length);
    while (str[i] && length)
    {
        j = 0;
        while (charset[j])
        {
            if (charset[j] == str[i])
            {
                printf("matched charset[j]: %c, str[i] : %c\n", charset[j], str[i]);
                length--;
                break ;
            }
            j++;
        }
        i++;
        // printf("length: %d\n", length);
    }
    printf("%d\n", length);
    if (length == 0)
        return (1);
    return (0);
}

int main(void)
{
    char *charset = "01NEWS";
    char *str = ".111111111";

    if (charset_finder(charset, str))
        printf("ok\n");
    else
        printf("pb\n");
    return (0);
}