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
void    checkPlayerPos(t_game *game);
void	zeroBlankContact(t_game *game);
void    checkIsLastElement(t_game *game);
bool    isEmptyLine(char *line);
void    floodFillCheck(t_game *game);

/*floor ceiling*/
void checkFloorCeiling(t_game *game);

//***** UTILITY *****
void    print_tlist(t_list *list);
bool    charset_finder(const char *charset, const char *str);
void    LLtoArrayConverter(t_game *game);
float   RadianToAngle (float radian);
float   angleToRadian (float angle);
void    drawLine(t_game *game, int x0, int y0, int x1, int y1, int color);
void    drawRectangle(t_game *game, int x, int y, int width, int height, int color);
void    drawRays3D(t_game *game);

/*clolors*/
int	create_rgb(int r, int g, int b);

/*renderring*/
void	renderGame(t_game *game);
void    drawFloorCeiling(t_game *game);
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);
void    ft_draw_img(t_game *game);
bool    import_textures(t_game *game);
void draw3d(t_game *game);
/*****************************************/
void    drawPlayer(t_game *game);
int     move(int keysym, t_game *game);
int     hande_move(int keysym, t_game *game);
/*initialisation*/
void initGameWindow(t_game *game);
void initGameParam(t_game *game);
void    coordInit(t_coord *coord);

//***** FREE *****
void freeCharArray(char ***array);

#endif