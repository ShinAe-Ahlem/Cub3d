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
int	ft_close_window(t_game *game);
void	window_size_setting(t_game *game);

//***** EVENT MANAGEMENT *****
int     move(int keysym, t_game *game);
int     handle_move(int keysym, t_game *game);
int 	close_window(int keysym, t_game *game);
void    close_event(t_game *game);


//***** ERROR MANAGEMENT *****

void    ft_error(char *code_error);

//***** CHECK MAP *****
bool    is_empty_line(char *line);
bool	checkdirection(char *line);
void	map_check_division(t_game *game);
size_t	last_digit_position(char *line);

void    export_map(t_game *game);
void    floodfill_check(t_game *game);
void    check_player_pos(t_game *game);
void	check_map_elements(t_game *game);
void	zero_blank_contact(t_game *game);
void    check_is_last_element(t_game *game);
void    check_export_textures(t_game *game);

char	**ft_read_map(char *filename);

/*floor ceiling*/
void check_floor_ceiling(t_game *game);

//***** UTILITY *****
void    print_tlist(t_list *list);
void    ll_toarray_converter(t_game *game);

float   angleToRadian (float angle);
float   RadianToAngle (float radian);

/******FORMAT CHECK*******/

bool	are_valid_texture_formats(t_game *game)
;
/**************************************/

bool	has_spaces(char *str);
bool	has_intruder(char *str);
bool    charset_finder(const char *charset, const char *str);
bool red_gree_blue(char *str);
/*clolors*/
int	create_rgb(int r, int g, int b);

/*renderring*/
int     render_next_frame(t_game *game);

void    render(t_game *game, int x);
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);

/*initialisation*/
void    initImage(t_game *game);
void    coordInit(t_coord *coord);
void    initGameParam(t_game *game);
void    initGameWindow(t_game *game);

//***** FREE *****
void free_all(t_game *game);
void free_part(t_game *game);
void free_char_array(char ***array);
#endif