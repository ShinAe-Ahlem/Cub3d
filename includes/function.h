#ifndef FUNCTION_H
# define FUNCTION_H

#include "../includes/game.h"

typedef struct s_img t_img;
typedef struct s_player t_player;
//***** CHECK ARGUMENTS *****

void    check_nb_arg(int ac);
void    check_arg(int ac, char **av);


//***** CHECK ENVIRONMENT *****

void	check_env(char **env);

//***** GAME LOADING *****

int	ft_create_window(t_game *game);

void	window_size_setting(t_game *game);

//***** EVENT MANAGEMENT *****
int     move(int keysym, t_game *game);
int     handle_move(int keysym, t_game *game);
int	    handle_keypress(int keysym, t_game *game);

//***** ERROR MANAGEMENT *****

void    ft_error(char *code_error);

//***** CHECK MAP *****

bool    isMap(char *line);
bool    isEmptyLine(char *line);
bool	checkDirection(char *line);

void    exportMap(t_game *game);
void    floodFillCheck(t_game *game);
void    checkPlayerPos(t_game *game);
void    checkMapElement(t_game *game);
void	zeroBlankContact(t_game *game);
void    checkIsLastElement(t_game *game);
void    checkExportTextures(t_game *game);

char	**ft_read_map(char *filename);

/*floor ceiling*/
void checkFloorCeiling(t_game *game);

//***** UTILITY *****
void    print_tlist(t_list *list);
void    LLtoArrayConverter(t_game *game);

float   angleToRadian (float angle);
float   RadianToAngle (float radian);

bool    charset_finder(const char *charset, const char *str);

/*clolors*/
int	create_rgb(int r, int g, int b);

/*renderring*/
int     renderNextFrame(t_game *game);

void    render(t_game *game, int x);
bool    import_textures(t_game *game);
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);

/*initialisation*/
void    initImage(t_game *game);
void    coordInit(t_coord *coord);
void    initGameParam(t_game *game);
void    initGameWindow(t_game *game);

//***** FREE *****
void free_all(t_game *game);
void freeCharArray(char ***array);
#endif