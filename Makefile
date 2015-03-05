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

CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./libft

CC = cc

LIBFT = ./libft/includes

SOURCE = ./srcs/main.c \
./srcs/get_next_line.c \
./srcs/ft_find_pwd.c

POINTO = $(SOURCE:.c=.o)

all: 
	make $(NAME)
	@echo "all: OK"

$(NAME): $(POINTO)
	@make -C libft
	gcc $(CFLAGS) -o $(NAME) $(POINTO) ./libft/libft.a

test:
	@gcc $(CFLAGS) -o $(NAME) $(POINTO) ./libft/libft.a
	@echo "test: OK"

clean:
	@make -C libft/ clean	
	@rm -rf $(POINTO)

fclean: clean
	@make -C libft/ fclean	
	@rm -rf $(NAME)
	@echo "fclean: OK"

re: fclean all

.PHONY: re fclean clean all $(NAME) test
