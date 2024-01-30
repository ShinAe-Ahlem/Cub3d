
#include "../libft/libft.h"

void    ft_error(char *code_error)
{
    write (2, code_error,ft_strlen(code_error));
    write(2, "\n", 1);
}


char **ft_read_map(char *filename)
{
    int fd;
    char **map_lines;/*soit on fixe une taille maxe soit allocation dynamique*/
    char *line;
    map_lines = NULL;
    // map_lines = malloc(1* sizeof(char*));
    // map_lines[0] = NULL;
    char **new;
    new = NULL;
    int j;
    // size_t len;
    int i;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        free(map_lines);
        exit(EXIT_FAILURE);
    }
    i = 0;
    ft_putstr_fd("\n*****************reading map*********************\n", 1);
    while((line = get_next_line(fd)) != NULL)
    {
        // ft_putstr_fd(line, 1);
        if (!map_lines)
        {
           ft_putstr_fd("\nread first line\n", 1);
           map_lines = malloc(2 * sizeof(char *));
            if (!map_lines)
                ft_error("malloc");
           map_lines[0] = ft_strdup(line);
           map_lines[1] = NULL;
           ft_putstr_fd(map_lines[0], 1);
           free(line);
           i = 1;
        }
        else
        {
            ft_putstr_fd("\nreading other lines\n", 1);
            printf("i = %d\n", i);
            new = malloc((i + 2) * sizeof(char*));
            if (!new)
                ft_error("malloc");
            j = 0;
            while (j < i)
            {
                new[j] = ft_strdup(map_lines[j]);
                // ft_putstr_fd(new[j], 1);
                j++;
            }
            new[j] = ft_strdup(line);
            // free(line);
            new[j + 1] = NULL;
        }
        j = 0;
        while(j < i)
        {
            free(map_lines[j]);
            j++;
        }
        free(map_lines);
        map_lines = new;
        i++;
        // j = 0;
        // while(j < i - 1)
        // {
        //     ft_putstr_fd(map_lines[j], 1);
        //     j++;
        // }
        // ft_putstr_fd(line, 1);
    }

    ft_putstr_fd("\nchecking if endofline\n", 1);
    close(fd);
    return(map_lines);
}

int	main(int ac, char **av, char **env)
{
    // t_game	game;

    // 1) init
    // 2) parsing (argument check, lecture cartte, map validity check)
    // 3) free / destroy

    // check_arg(ac, av);
    // check_env(env);

    // ft_create_window(&game);
    char **map_lines = ft_read_map(av[1]);
    if (!map_lines)
        ft_error("invalid map");
    ft_putstr_fd("yahooooooooo\n",1);
    /* we will exit the loop if there's no window left, and execute this code */
}
