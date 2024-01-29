
NAME= cub3D
SRC_DIR = ./srcs
SRCS= $(wildcard $(SRC_DIR)/*.c)

# SRCS_BONUS=

INC_DIR= -I./incs

OBJS= ${SRCS:.c=.o}

OBJS_BONUS= ${SRCS_BONUS:.c=.o}
CC= cc
FLAGS= -Wall -Wextra -Werror -g3

RM=rm -f

all: $(NAME)

${NAME}: $(OBJS)
	cd minilibx-linux;make;cd ..
	$(CC) $(FLAGS) $(OBJS) -Lminilibx-linux -L/usr/lib -Iminilibx-linux/ -o $(NAME) -lXext -lX11 -lm -lmlx_Linux
	
# bonus: $(OBJS_BONUS)
# 	cd minilibx-linux;make;cd ..
# 	$(CC) $(FLAGS) $(OBJS_BONUS) -Lminilibx-linux -L/usr/lib -Iminilibx-linux/ -o $(NAME)_bonus -lXext -lX11 -lm -lmlx_Linux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -MP -I/usr/include -Iminilibx-linux/ -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re #bonus