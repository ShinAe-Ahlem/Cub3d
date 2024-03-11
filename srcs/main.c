#include "../includes/game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;



int	main(int ac, char **av, char **env)
{
    t_game	game;

    // 1) init
    // 2) parsing (argument check, lecture cartte, map validity check)
    // 3) free / destroy

    check_arg(ac, av);
    check_env(env);

    initGameParam(&game);
    printf("\n<< main()>>\n");
    game.mapfile = ft_read_map(av[1]);
    if (!game.mapfile)
    {
        free_all(&game);
        return (1);
    }
    checkMapElement(&game);
    ft_create_window(&game);
    
    /* we will exit the loop if there's no window left, and execute this code */
    // mlx_destroy_display(game.mlx_ptr);
    // free(game.mlx_ptr);
    printf("\n<< main() correctly closed >>\n");
}
