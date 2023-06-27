# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 12:46:56 by kglebows          #+#    #+#              #
#    Updated: 2023/06/27 15:50:55 by kglebows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft.a
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = 	push_swap.c utils.c input.c ini.c \
		stack_pushRotate.c stack_reverseRotate.c stack_swap.c \
		test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all

norm: $(SRCS)
	$(shell norminette | grep Error)

.PHONY: all clean fclean norm re