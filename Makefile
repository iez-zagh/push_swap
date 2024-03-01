RED_TEXT =\033[1;31m
GREEN_TEXT =\033[1;32m
YELLOW_TEXT =\033[1;33m
RESET_TEXT =\033[0m

NAME = push_swap
CC = gcc
FLAGS = -Wextra -Wall -Werror
# printf things
# the source codes
M_SOURCES = push_swap.c push_swap_utils.c helper_functions.c ft_split.c \
			linked_list.c stack_moves.c push_swap_utils_2.c linked_list_2.c stack_moves_2.c \
			sorting.c fill_stack.c min_max.c moving_to_b.c sort_more_6.c best_target.c
M_OBJECTS = ${M_SOURCES:.c=.o}

all: $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(M_OBJECTS)
	@echo "$(GREEN_TEXT)[the excutable created successfuly]$(RESET_TEXT)"
	@$(CC) $(FLAGS)  $(M_OBJECTS) -o $(NAME)


clean:
	@rm -f $(M_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfuly$(RESET_TEXT)"
fclean : clean
	@rm -f $(NAME)
	@echo "$(RED_TEXT)the excutable files removed successfuly$(RESET_TEXT)"

re : fclean all

.PHONY : clean