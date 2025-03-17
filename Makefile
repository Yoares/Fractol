NAME = fractol

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = fractol.c mandelboard.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)  # Ensure MLX is compiled first
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)  # Clean MLX build files

re: fclean all

.PHONY: all clean fclean re
