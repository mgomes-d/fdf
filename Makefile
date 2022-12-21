NAME = fdf

SRCS = $(wildcard src/*.c utils/*/*.c)

OBJ = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -O1 -O2 -O3

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
