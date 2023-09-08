# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:30:52 by feberman          #+#    #+#              #
#    Updated: 2023/09/08 10:28:00 by feberman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CFLAGS= -Wall -Werror -Wextra

LIBFT= libft/libft.a

SRCs = 	push_swap.c input_validation.c split.c free.c input_utils.c error.c array.c list.c stacks.c ops_push.c ops_rotate.c\
		sorted_precheck.c math_utils.c beam.c presort.c ops_out.c
OBJs = $(SRCs:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJs)
	cc $(CFLAGS) $(OBJs) $(LIBFT) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd libft && make

clean:
	rm -f *.o
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re