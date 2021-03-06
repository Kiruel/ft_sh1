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

NAME = minishell1

CFLAGS = -Wall -Werror -Wextra -I ./includes -I ./libft/ -g

SRCS = srcs/

S = $(SRCS)main.c \
$(SRCS)ft_error.c \
$(SRCS)ft_recup_env.c \
$(SRCS)get_next_line.c \
$(SRCS)ft_tools.c \
$(SRCS)ft_builtings.c \
$(SRCS)ft_cd.c \
$(SRCS)ft_cd_features.c \
$(SRCS)ft_setenv.c \
$(SRCS)ft_env.c \
$(SRCS)ft_unsetenv.c

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
