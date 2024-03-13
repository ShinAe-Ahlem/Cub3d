#include "../includes/game.h"

void export_texture(t_game *game)
{
    int i; 
    i = game->pos - 4;


    //Que se passe t-il quand il y a des espaces devant la direction des textures
    //ex) [           NO temp/temp.xpm]
    game->texture =(t_texture *) malloc(1 * sizeof(t_texture *));
    if (!game->texture)
    {
        exit(EXIT_FAILURE);
    }
    while(i < game->pos)
    {
        if (!ft_strncmp("NO ", game->mapfile[i], 3))
        {
            game->texture->NO = ft_strdup(game->mapfile[i]);
            dprintf(1,"game->tex->NO = %s\n", game->texture->NO);
        }
        else if (!ft_strncmp("SO ", game->mapfile[i], 3))
        {
            game->texture->SO = ft_strdup(game->mapfile[i]);
            dprintf(1,"game->tex->SO = %s\n", game->texture->SO);

        }
        else if (!ft_strncmp("EA ", game->mapfile[i], 3))
        {
            game->texture->EA = ft_strdup(game->mapfile[i]);
            dprintf(1,"game->tex->EA = %s\n", game->texture->EA);

        }
        else if (!ft_strncmp("WE ", game->mapfile[i], 3))
        {
            game->texture->WE = ft_strdup(game->mapfile[i]);
            dprintf(1,"game->tex->WE = %s\n", game->texture->WE);

        }
        i++;
    }

}

void texture_file_exist(t_game * game, char *texture, int texNum)
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
    texture = NULL;
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
   game->texFiles[texNum] = ft_strdup(filename);
   dprintf(1, "\n\n\n\ntexture = %s\n\n\\n", texture);
   free(filename);
    close (fd);
}


void    checkTextures(t_game *game, int *count)
{
    while (game->mapfile[game->pos])
    {
        // printf("inside checkTextures, line = %s \n", game->mapfile[game->pos]);
        if (game->mapfile[game->pos][0] == '\n')
            break ;
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
        if (!check_extension(game->texture->NO) || \
                !check_extension(game->texture->SO) || \
                !check_extension(game->texture->EA) || \
                !check_extension(game->texture->WE))
        {
            // free 
            ft_error(ERROR_FILE_EXT);
            exit(EXIT_FAILURE);
        }
        game->texFiles = malloc(5 * sizeof(char *));
        game->texFiles[4] = NULL;
        texture_file_exist(game, game->texture->NO, 0);
        texture_file_exist(game, game->texture->SO, 2);
        texture_file_exist(game, game->texture->EA, 1);
        texture_file_exist(game, game->texture->WE, 3);
    	dprintf(1,"\nin check && export : tex = %s\n", game->texture->NO);
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
	dprintf(1,"\nin check && export : tex = %s\n", game->texFiles[0]);
    dprintf(1,"\nhihihi\n");

}
