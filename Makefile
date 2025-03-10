NAME = fractol

CC = cc

FLAGS = -Wall -Wextra -Werror 

SRCS = fractol.c mandelboard.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Lminilibix-linux -lmlx -lXext -lX11 -lm -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re