RED_TEXT =\033[1;31m
GREEN_TEXT =\033[1;32m
YELLOW_TEXT =\033[1;33m
RESET_TEXT =\033[0m

NAME = push_swap
CC = cc
FLAGS = -Wextra -Wall -Werror
# printf things
PRINTF_PATH = ./my_printf
PRINTF_NAME = ftprintf
# the source codes
M_SOURCES = push_swap.c push_swap_utils.c fill_stack.c helper_functions.c ft_split.c \
			linked_list.c stack_moves.c
M_OBJECTS = ${M_SOURCES:.c=.o}

all: printf $(NAME)


%.o: %.c push_swap.h
	@$(CC)  $(FLAGS) -c $< -o $@

printf: push_swap.h
	@make -C $(PRINTF_PATH)

$(NAME): $(M_OBJECTS)
	@echo "$(GREEN_TEXT)[the excutable created successfuly]$(RESET_TEXT)"
	@$(CC)  $(FLAGS) -L$(PRINTF_PATH) -lftprintf $(M_OBJECTS) -o $(NAME)


clean:
	@rm -f $(M_OBJECTS)
	@make clean -C $(PRINTF_PATH)
	@echo "$(RED_TEXT)object files removed successfuly$(RESET_TEXT)"
fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_PATH)
	@echo "$(RED_TEXT)the excutable files removed successfuly$(RESET_TEXT)"

re : fclean all printf

.PHONY : clean