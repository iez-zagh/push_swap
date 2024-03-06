RED_TEXT =\033[1;31m
GREEN_TEXT =\033[1;32m
YELLOW_TEXT =\033[1;33m
RESET_TEXT =\033[0m

NAME = push_swap
BONUS = checker
CC = gcc
FLAGS = -Wextra -Wall -Werror -g

# the source codes
M_SOURCES = push_swap.c push_swap_utils.c helper_functions.c ft_split.c \
			linked_list.c stack_moves.c push_swap_utils_2.c linked_list_2.c stack_moves_2.c \
			sorting.c fill_stack.c min_max.c moving_to_b.c sort_more_6.c best_target.c

B_SOURCES = utils2_bonus.c utils_bonus.c checker_bonus.c fill_stack_bonus.c \
			ft_split_bonus.c linked_list_bonus.c prepare_stack_bonus.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c apply_ins_bonus.c \
			stack_moves_bonus.c stack_moves2_bonus.c
B_OBJECTS = ${B_SOURCES:.c=.o}
M_OBJECTS = ${M_SOURCES:.c=.o}

all: $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c push_swap_bonus.h
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS)

$(NAME): $(M_OBJECTS)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"
	@$(CC) $(FLAGS) $(M_OBJECTS) -o $(NAME)

$(BONUS): $(B_OBJECTS)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"
	@$(CC) $(FLAGS) $(B_OBJECTS) -o $(BONUS)

clean:
	@rm -f $(M_OBJECTS)
	@rm -f $(B_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfully$(RESET_TEXT)"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "$(RED_TEXT)the executable files removed successfully$(RESET_TEXT)"

re : fclean all

.PHONY : clean
