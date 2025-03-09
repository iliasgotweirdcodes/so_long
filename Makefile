
NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -lmlx -framework OpenGL -framework AppKit

SRC =  mandatory/parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c mandatory/error.c mandatory/map.c mandatory/ft_strcmp.c \
		mandatory/read_map.c mandatory/free.c mandatory/valid_file.c mandatory/path.c mandatory/set_map.c \
		mandatory/so_long.c mandatory/game.c mandatory/moves.c mandatory/ft_putnbr.c mandatory/helpers.c

SRC_BONUS = bonus/parsing_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c bonus/error_bonus.c bonus/map_bonus.c bonus/ft_strcmp_bonus.c \
		bonus/read_map_bonus.c bonus/free_bonus.c bonus/valid_file_bonus.c bonus/path_bonus.c bonus/set_map_bonus.c bonus/ft_itoa_bonus.c \
		bonus/so_long_bonus.c bonus/game_bonus.c bonus/moves_bonus.c  bonus/helpers_bonus.c bonus/enemy_animation.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIBS) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	$(CC) $(LIBS) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

%.o: %.c so_long.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c so_long_bonus.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

