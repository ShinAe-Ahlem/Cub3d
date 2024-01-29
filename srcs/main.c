#include "../includes/game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

int	render(t_data *data)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (data->win_ptr != NULL)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
    return (0);
}

void ft_read_map(char *filename)
{
    int fd;
    char *map_lines[100];/*soit on fixe une taille maxe soit allocation dynamique*/
    char *line;
    // size_t len;
    int i;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    i = 0;
    ft_putstr_fd("\n*****************reading map*********************\n", 1);
    while((line = get_next_line(fd)) != NULL)
    {
        ft_putstr_fd(line, 1);
        map_lines[i]= ft_strdup(line);
        free(line);
        i++;
    }
    ft_putstr_fd(line, 1);
    ft_putstr_fd("\nchecking if endofline\n", 1);
    close(fd);
}

int	main(int ac, char **av, char **env)
{
    t_game	game;

    // 1) init
    // 2) parsing (argument check, lecture cartte, map validity check)
    // 3) free / destroy

    check_arg(ac, av);
    check_env(env);

    ft_create_window(&game);
    ft_read_map(av[1]);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(game.mlx_ptr);
    free(game.mlx_ptr);
}
