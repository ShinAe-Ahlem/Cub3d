#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include <../minilibx-linux/mlx.h>
#include "../includes/game.h"
#include "../libft/libft.h"
#include <errno.h>
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

#define ERROR1 "INVALID ARGS"

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return (0);
}

int	render(t_data *data)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (data->win_ptr != NULL)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
    return (0);
}

void	window_size_setting(t_game *game)
{
	mlx_get_screen_size(game->mlx_ptr, &game->screen_x, &game->screen_y);
	printf("\nScreen size : %d x %d\n", game->screen_x, game->screen_y);
    game->window_x = game->screen_x * 0.9;
    game->window_y = game->screen_y * 0.9;
}

int	ft_create_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (MLX_ERROR);
    window_size_setting(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->window_x), (game->window_y),
			game->game_name);
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
        free(game->win_ptr);
		return (MLX_ERROR);
	}
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
	return (1);
}

void    ft_error(char *code_error)
{
    write (2, code_error,ft_strlen(code_error));
    write(2, "\n", 1);
}

void    check_nb_arg(int ac)
{
    if (ac != 2)
    {
        ft_error (ERROR1);
        exit (EXIT_FAILURE);
    }
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

    check_nb_arg(ac);
    (void)env;
    (void)av;


    ft_create_window(&game);
    ft_read_map(av[1]);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(game.mlx_ptr);
    free(game.mlx_ptr);
}
