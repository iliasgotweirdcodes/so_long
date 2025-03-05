
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -lmlx -framework OpenGL -framework AppKit

SRC =  mandatory/parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c mandatory/error.c mandatory/map.c mandatory/ft_strcmp.c \
		mandatory/read_map.c mandatory/free.c mandatory/valid_file.c mandatory/path.c mandatory/set_map.c \
		mandatory/so_long.c mandatory/game.c mandatory/moves.c mandatory/ft_putnbr.c mandatory/helpers.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIBS) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c so_long.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
