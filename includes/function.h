/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:01:05 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/25 10:58:55 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "../includes/game.h"
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct s_img	t_img;
typedef struct s_player	t_player;
typedef struct s_list	t_list;
typedef struct s_game	t_game;
typedef struct s_coord	t_coord;
//***** CHECK ARGUMENTS *****

void					check_nb_arg(int ac);
void					check_arg(int ac, char **av);

//***** CHECK ENVIRONMENT *****

void					check_env(char **env);

//***** GAME LOADING *****

int						ft_create_window(t_game *game);
int						ft_close_window(t_game *game);
void					window_size_setting(t_game *game);

//***** EVENT MANAGEMENT *****
int						move(int keysym, t_game *game);
int						handle_move(int keysym, t_game *game);
int						esc_close_window(int keysym, t_game *game);
void					close_event(t_game *game);

//***** ERROR MANAGEMENT *****

void					ft_error(char *code_error);

//***** CHECK MAP *****
bool					is_empty_line(char *line);
bool					checkdirection(char *line);
void					map_check_division(t_game *game);
size_t					last_digit_position(char *line);

void					export_map(t_game *game);
void					floodfill_check(t_game *game);
void					find_player_position(t_game *game, t_coord *player_pos);
void					check_player_pos(t_game *game);
void					check_map_elements(t_game *game);
void					zero_blank_contact(t_game *game);
void					check_is_last_element(t_game *game);
void					check_export_textures(t_game *game);

char					**ft_read_map(char *filename);

void					texlines_null_check(t_game *game, int *j);
void					file_is_directory_check(char **filename,
							struct stat *file_stat,
							t_game *game, int fd);
void					fd_error_check(int fd, char **filename, t_game *game);
void					texture_files_exist_init(int *i, int *j, int *fd,
							char **filename);

/* floor ceiling */
void					check_floor_ceiling(t_game *game, int *c_flag,
							int *f_flag);

//***** UTILITY *****
void					print_tlist(t_list *list);
void					ll_toarray_converter(t_game *game);

/******FORMAT CHECK*******/
bool					are_valid_texture_formats(t_game *game);

/**************************************/

bool					has_spaces(char *str);
bool					has_intruder(char *str);
bool					charset_finder(const char *charset, const char *str);
bool					red_gree_blue(char *str);

/*clolors*/
int						create_rgb(int r, int g, int b);

/*renderring*/
int						render_next_frame(t_game *game);

void					render(t_game *game, int x);
void					my_mlx_pixel_put(t_img *image, int x, int y, int color);
void					perform_dda(t_game *game);

/*initialisation*/
void					init_image(t_game *game);
void					init_game_param(t_game *game);
void					init_game_window(t_game *game);

//***** FREE *****
void					free_tex_files(t_game *game);
void					free_all(t_game *game);
void					free_part(t_game *game);
void					free_char_array(char ***array);

/******texture check*/
void					check_textures_dimensions(t_game *game);

/***************key press**************/

void					up_down(int keysym, t_game *game);
void					rot_right(int keysym, t_game *game, double olddir_x,
							double oldplane_x);
void					rot_left(int keysym, t_game *game, double olddir_x,
							double oldplane_x);
void					lef_right(int keysym, t_game *game, double move_speed);
void					forward_backward(int keysym, t_game *game,
							double move_speed);

/*****parsing*****/
bool					is_direction_line(char *line);
bool					is_map(t_game *game, char *line);
bool					is_floor_ceilnig_line(char *line);

void					handle_map(t_game *game);
void					handle_fc_dir(t_game *game);
void					handle_fc(t_game *game, int *f, int *c_flag,
							int *f_flag);
#endif