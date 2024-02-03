#ifndef FUNCTION_H
# define FUNCTION_H

#include "../includes/game.h"


//***** CHECK ARGUMENTS *****

void    check_nb_arg(int ac);
void    check_arg(int ac, char **av);


//***** CHECK ENVIRONMENT *****

void	check_env(char **env);



//***** GAME LOADING *****

int	ft_create_window(t_game *game);
void	window_size_setting(t_game *game);

//***** EVENT MANAGEMENT *****
int	handle_keypress(int keysym, t_game *game);


//***** ERROR MANAGEMENT *****

void    ft_error(char *code_error);

//***** CHECK MAP *****

char	**ft_read_map(char *filename);
void    checkMapElement(t_game *game);
void    checkExportTextures(t_game *game);
bool	checkDirection(char *line);
bool    isMap(char *line);
void    exportMap(t_game *game);
void checkPlayerPos(t_game *game);

/*floor ceiling*/
void checkFloorCeiling(t_game *game);

//***** UTILITY *****

void    print_tlist(t_list *list);
bool charset_finder(const char *charset, const char *str);
void    LLtoArrayConverter(t_game *game);

#endif