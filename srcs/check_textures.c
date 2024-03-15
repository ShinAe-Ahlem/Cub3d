#include "../includes/game.h"

void export_texture(t_game *game)
{
    int i; 
    i = game->pos;

    game->texLines = malloc(5 * sizeof(char*));
    if (!game->texture)
    {
        free_all(game);
        exit(EXIT_FAILURE);
    }
    while(i < game->pos + 4)
    {
        if (!ft_strncmp("NO ", game->mapfile[i], 3))
        {
            game->texLines[0] = ft_strdup(game->mapfile[i]);
        }
        else if (!ft_strncmp("EA ", game->mapfile[i], 3))
        {
            game->texLines[1] = ft_strdup(game->mapfile[i]);
        }
        else if (!ft_strncmp("SO ", game->mapfile[i], 3))
        {
            game->texLines[2] = ft_strdup(game->mapfile[i]);
        }
        else if (!ft_strncmp("WE ", game->mapfile[i], 3))
        {
            game->texLines[3] = ft_strdup(game->mapfile[i]);
        }
        i++;
    }
}

void textureFilesExist(t_game * game)
{
    int fd;
    char *filename;
    struct stat file_stat;
    int i;

    int j;

    j= 0;
    game->texFiles = ft_calloc(sizeof(char *), 4);
    while(j < 4)
    {
        i = 3;    
        while (game->texLines[j][i] == ' ')
            i++;
        filename = ft_substr(game->texLines[j], i, ft_strlen(game->texLines[j]) - (i + 1));
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
        game->texFiles[j] = ft_strdup(filename);
        free(filename);
        filename = NULL;
            close (fd);
        j++;
    }
}

void    checkTextures(t_game *game, int *count)
{
    while (game->mapfile[game->pos])
    {
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



// void check_game_textures(t_game *game)
// {
//     int count;
//     count= 0;

//     checkTextures(game, &count);
//     if (count == 4)
//     {
//         // game->texture.pos = game->pos;
//         export_texture(game);
      
//         printf("inside checkTextures, line = %s \n", game->texture->EA);
//         if (!check_extension(game->texture->NO) || \
//                 !check_extension(game->texture->SO) || \
//                 !check_extension(game->texture->EA) || \
//                 !check_extension(game->texture->WE))
//         {
//             // free 
//             ft_error(ERROR_FILE_EXT);
//             exit(EXIT_FAILURE);
//         }
//         game->texFiles = malloc(4 * sizeof(char *));
//         texture_file_exist(game, game->texture->NO, 0);
//         texture_file_exist(game, game->texture->SO, 2);
//         texture_file_exist(game, game->texture->EA, 1);
//         texture_file_exist(game, game->texture->WE, 3);
//     }
//     else
//     {
//         ft_perror(ERROR_LOAD_DIR);
//         //free whatever you need to
//         exit(EXIT_FAILURE);
//     }
//         printf("seg here \n");

// }

    
static bool hasValidPrefix(char *texture)
{
     if (!ft_strncmp("NO ", texture, 3))
        return(true);
    else if (!ft_strncmp("SO ", texture, 3))
        return(true);
    else if (!ft_strncmp("WE ", texture, 3))
        return(true);
    else if (!ft_strncmp("EA ", texture, 3))
        return(true);
    ft_error("not valid prefix\n");
    return(false);
}

static bool areValidExtentionFormats(t_game *game)
{
    int i;
    i = game->pos;
    while(i < game->pos + 4)
    {
        if (game->mapfile[i][0] == '\n' )
        {
            ft_error("found empty line or format is invalid");
            return(false);
        }
        if (!hasValidPrefix(game->mapfile[i]))
            return(false);
        i++;
    }
    return(true);
}
void    checkExportTextures(t_game *game)
{
    while (game->mapfile[game->pos][0] == '\n')
        game->pos++;
    game->texture = ft_calloc(1 * sizeof(t_texture *), 1);
    if (!game->texture)
    {
        free_all(game);
        exit(EXIT_FAILURE);
    }
    if (!areValidExtentionFormats(game))
    {
        free_all(game);
        exit(EXIT_FAILURE);   
    }
    export_texture(game);
    textureFilesExist(game);
    game->pos += 3;
    while (game->mapfile[game->pos][0] == '\n')
        game->pos++;
}