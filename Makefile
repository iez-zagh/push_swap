NAME = push_swap
CC = gcc
FLAGS = -Wextra -Wall -Werror

M_SOURCES = push_swap.c push_swap_utils.c
M_OBJECTS = ${M_SOURCES:.c=.o}

all: $(NAME)

$(NAME): $(M_OBJECTS)
	$(CC) $(FLAGS) $(M_OBJECTS) -o $(NAME)

clean:
	rm -f $(M_OBJECTS)
fclean : clean
	rm -f $(NAME)
re : fclean all