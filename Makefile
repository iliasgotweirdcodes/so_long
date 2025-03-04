
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -lmlx -framework OpenGL -framework AppKit

SRC =  parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_split.c error.c map.c ft_strcmp.c \
		read_map.c free.c valid_file.c path.c set_map.c so_long.c game.c moves.c \

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
