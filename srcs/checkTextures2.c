#include "../includes/game.h"

void	texlines_null_check(t_game *game, int *j)
{
	if (game->texLines[*j] == NULL)
	{
		ft_perror(ERROR_LOAD_DIR);
		free_part(game);
		exit(EXIT_FAILURE);
	}
}

void	file_is_directory_check(char **filename, struct stat *file_stat,
		t_game *game, int fd)
{
	if (fstat(fd, file_stat) == -1)
		ft_perror(ERROR_FILE_STATUS);
	if (S_ISDIR(file_stat->st_mode))
	{
		printf("filename : %s\n", *filename);
		ft_error(ERROR_XPM_DIR);
		free_part(game);
		free(*filename);
		close(fd);
		exit(EXIT_SUCCESS);
	}
}

void	fd_error_check(int fd, char **filename, t_game *game)
{
	if (fd == -1)
	{
		ft_perror("Open error (Tips : check file permission)");
		if (*filename)
			free(*filename);
		free_part(game);
		exit(EXIT_FAILURE);
	}
}

void    texture_files_exist_init(int *i, int *j, int *fd, char **filename)
{
    *j = 0;
	*fd = 0;
	*filename = NULL;
	*i = 0;
}
