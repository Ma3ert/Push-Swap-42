# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 13:30:14 by yait-iaz          #+#    #+#              #
#    Updated: 2022/02/22 12:40:41 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = swap.c push.c reverse_rotate.c rotate.c utils.c main.c sorting.c \
		arg_checker.c pivot.c index.c lis.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
