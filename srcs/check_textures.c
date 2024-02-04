#include "../includes/game.h"

void export_texture(t_game *game)
{
    int i; 
    i = game->pos - 4;


    //Que se passe t-il quand il y a des espaces devant la direction des textures
    //ex) [           NO temp/temp.xpm]
    while(i < game->pos)
    {
        if (!ft_strncmp("NO ", game->mapfile[i], 3))
            game->texture.NO = ft_strdup(game->mapfile[i]);
        else if (!ft_strncmp("SO ", game->mapfile[i], 3))
            game->texture.SO = ft_strdup(game->mapfile[i]);
        else if (!ft_strncmp("EA ", game->mapfile[i], 3))
            game->texture.EA = ft_strdup(game->mapfile[i]);
        else if (!ft_strncmp("WE ", game->mapfile[i], 3))
            game->texture.WE = ft_strdup(game->mapfile[i]);
        i++;
    }
    // Test print
    printf("\nTEST PRINT : succesfully created [game->texture.(directions)]\n");
    printf("%s",game->texture.NO);
    printf("%s",game->texture.SO);
    printf("%s",game->texture.EA);
    printf("%s",game->texture.WE);
    printf("\n");

}

void texture_file_exist(char *texture)
{
    int fd;
    char *filename;
    struct stat file_stat;
    int i;

    i = 3;    
    while (texture[i] == ' ')
        i++;
    filename = ft_substr(texture, i, ft_strlen(texture) - (i + 1));
    free(texture);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_perror(ERROR_OPEN);
        /*free_game*/
        exit(EXIT_FAILURE);
    }
    if (fstat(fd, &file_stat) == -1)
        ft_perror (ERROR_FILE_STATUS);
    if (S_ISDIR(file_stat.st_mode))
    {
        printf("filename : %s\n", filename);
        ft_error(ERROR_XPM_DIR);
        /*free game*/
        free(filename);
        close(fd);
        exit (EXIT_SUCCESS);
    }
    free(filename);
    close (fd);
}


void    checkTextures(t_game *game, int *count)
{
    while (game->mapfile[game->pos])
    {
        // printf("inside checkTextures, line = %s \n", game->mapfile[game->pos]);
        if (game->mapfile[game->pos][0] == '\n')
        {
            ft_putstr_fd("Enter found (end of lecture : texture setting part\n", 1);
            break ;
        }
        if (checkDirection(game->mapfile[game->pos]))
        {
            free_table(game->mapfile);
            exit(EXIT_FAILURE);
        }
        else
            (*count)++;
        (game->pos)++;
    }  
}

bool	check_extension(char *line)
{
	int	i;

	i = ft_strlen(line) - 2;
	if (line[i] == 'm' && line[i - 1] == 'p'
		&& line[i - 2] == 'x' && line[i - 3] == '.')
		return (1);
	return (0);
}

void check_game_textures(t_game *game)
{
    int count;
    count= 0;

    checkTextures(game, &count);
    if (count == 4)
    {
        // game->texture.pos = game->pos;
        export_texture(game);
        if (!check_extension(game->texture.NO) || \
                !check_extension(game->texture.SO) || \
                !check_extension(game->texture.EA) || \
                !check_extension(game->texture.WE))
        {
            // free 
            ft_error(ERROR_FILE_EXT);
            exit(EXIT_FAILURE);
        }
        texture_file_exist(game->texture.NO);
        texture_file_exist(game->texture.SO);
        texture_file_exist(game->texture.EA);
        texture_file_exist(game->texture.WE);
    }
    else
    {
        ft_perror(ERROR_LOAD_DIR);
        //free whatever you need to
        exit(EXIT_FAILURE);
    }
}

void    checkExportTextures(t_game *game)
{
    while (game->mapfile[game->pos][0] == '\n')
        game->pos++;
    check_game_textures(game);
}
