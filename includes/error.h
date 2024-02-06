#ifndef ERROR_H
# define ERROR_H

# include "../includes/game.h"

# define ERROR_NB_ARG "Invalid number of arguments.\nTry [./cub3d (map file)]"
# define ERROR_ENV_NF "System environment not found."
# define ERROR_ENV_DISP "System environment does not support graphic display."
# define ERROR_LOAD_DIR "A problem has occured while loading map textures."
# define ERROR_FILE_EXT "Cannot recognize the game file (check file extension)"
# define ERROR_FILE_STATUS "Error has occured while getting file status."
# define ERROR_OPEN "Error has occured while opening a file"
# define ERROR_XPM_DIR "Error : loaded texture may be a directory"
# define ERROR_NO_MAP "Loaded file does not seem to contain a map"
# define ERROR_NO_MATCH_CHAR "Unexpected character has been found"
# define ERROR_SPACE "Unexpected space has been found"
# define ERROR_MULT_PLA_POS "There are too many or no player position on map"
# define ERROR_MAP_UNCLOSED "Map is not closed"
# define ERROR_MAP_SPLITTED "Map is splitted by an empty one or not last element is file"
# define ERROR_FF_FAILED "Map contains inaccessible spots for player"
# define ERROR_MLX 1

#endif