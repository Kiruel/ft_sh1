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

CFLAG = -Wall -Wextra -Werror -I ./includes

LIBFT = ./libft/includes

SOURCE = main.c \
get_next_line.c \
ft_find_pwd.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)
	@echo "all: OK"

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c $(CFLAG) $(SOURCE) -I $(LIBFT)
	@gcc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a
	@make clean

test:
	@cc -c $(CFLAG) $(SOURCE)
	@cc $(CFLAG) -o $(NAME) $(POINTO) ./libft/libft.a
	@make clean
	@echo "test: OK"

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean: OK"

re: fclean all

.PHONY: re fclean clean all $(NAME) test
