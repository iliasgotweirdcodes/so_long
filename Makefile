
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -lmlx -framework OpenGL -framework AppKit

SRC =  parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_split.c error.c map.c ft_strcmp.c \

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c so_long.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
