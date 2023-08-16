# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:20:23 by kglebows          #+#    #+#              #
#    Updated: 2023/08/16 18:58:20 by kglebows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFTNAME = libft.a
LIBFTDIR = src/libft
OBJDIR = ./bin
SRCDIR = ./src

SRC = 			push_swap.c
SRC_BONUS = 	checker.c
SRC_GNL = 		gnl/get_next_line_utils.c gnl/get_next_line.c
SRC_INI = 		ini/ini.c ini/utils.c
SRC_SORT = 		sort/distance.c sort/phase1.c sort/phase2.c sort/solve.c \
				sort/sort.c sort/utils.c
SRC_STACK = 	stack/push.c stack/rotate.c stack/rrotate.c stack/swap.c \
				stack/stack.c

SRCS = $(SRC) $(SRC_INI) $(SRC_SORT) $(SRC_STACK)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

SRCS_BONUS = $(SRC_BONUS) $(SRC_INI) $(SRC_STACK) $(SRC_GNL)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Isrc -c $< -o $@

all: $(NAME)

bonus: makelibft $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(OBJDIR)/libft -lft

makelibft:
	@make -C $(LIBFTDIR)
	@mkdir -p $(OBJDIR)/libft
	@mv $(LIBFTDIR)/*.o $(OBJDIR)/libft/
	@mv $(LIBFTDIR)/$(LIBFTNAME) $(OBJDIR)/libft/

$(NAME): makelibft $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(OBJDIR)/libft -lft

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFTDIR) fclean
	
re: fclean all

norm:
	$(shell norminette | grep Error)

.PHONY: all clean fclean norm re bonus

#tester
TESTER_GET  =   https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER      =   ./ps_tester.pl

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
