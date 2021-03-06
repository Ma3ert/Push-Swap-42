# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 13:30:14 by yait-iaz          #+#    #+#              #
#    Updated: 2022/03/14 15:24:31 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = swap.c push.c reverse_rotate.c rotate.c utils.c main.c sorting.c \
		arg_checker.c value.c index.c lis.c stack_operation.c distance.c \
		best_element.c leaks.c get_next_line_utils.c ft_split.c adjust_arg.c
SRC_B = checker.c get_next_line.c get_next_line_utils.c arg_checker.c \
		push.c reverse_rotate.c rotate.c utils.c swap.c stack_operation.c \
		leaks.c ft_split.c adjust_arg.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = push_swap
BONUS = checker
HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_B) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_B) -o $(BONUS)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
