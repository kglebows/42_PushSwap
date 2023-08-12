# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 12:46:56 by kglebows          #+#    #+#              #
#    Updated: 2023/08/12 12:38:31 by kglebows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft.a
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = 	push_swap.c utils.c input.c ini.c phase1.c phase2.c \
		stack_pushRotate.c stack_reverseRotate.c stack_swap.c \
		distanceB.c sort.c utils2.c
OBJS = $(SRCS:.c=.o)
TESTER_GET  =   https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER      =   ./ps_tester.pl


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
	
$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)
3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100
5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100
100: $(NAME) $(TESTER)
	perl $(TESTER) 100 100
500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100
	
.PHONY: all clean fclean norm re