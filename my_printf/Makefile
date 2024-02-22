# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 22:01:56 by iez-zagh          #+#    #+#              #
#    Updated: 2024/02/19 18:46:55 by iez-zagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED_TEXT =\033[1;31m
GREEN_TEXT =\033[1;32m
YELLOW_TEXT =\033[1;33m
RESET_TEXT =\033[0m

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
RM = rm -f

SOURCES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_base.c ft_print_adress.c \
			ft_putnbr_uns.c ft_printf.c

OBJS = ${SOURCES:.c=.o}

all : $(NAME)

%.o : %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN_TEXT)[the excutable created successfuly]$(RESET_TEXT)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean all