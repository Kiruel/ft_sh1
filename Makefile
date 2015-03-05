#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2014/12/31 09:36:11 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

CFLAGS = -Wall -Werror -Wextra -I ./includes -I ./libft/headers -g

SRCS = srcs/

S = $(SRCS)main.c \
$(SRCS)ft_error.c

O = $(S:.c=.o)

CC=cc

#####   #####

all: $(NAME)
	@echo "all: OK"

$(NAME): $(O)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(O) -L./libft/ -lft

libft:
	make re -C libft/

clean:
	@make -C libft/ clean
	@rm -rf $(O)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "fclean: OK"

ffclean:
	@make -C libft/ fclean
	@make fclean

re: fclean all

.PHONY: re fclean clean all libft
