#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguthert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 15:25:02 by jguthert          #+#    #+#              #
#    Updated: 2016/05/31 17:27:43 by jguthert         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##=-  Compilatator -=##

NAME = ft_select
CC = gcc


##=-  FLAGS -=##

CFLAGS = -Wall -Wextra -Werror


##=-  PATH  -=##


##=-  Rules -=##

LIB := libft/libft.a
IFLAGS := -I include/ -I libft/includes
LFLAGS := -L libft/ -lft -lncurses


##=-  Colors  -=##

GREEN:="\033[1;32m"
EOC:="\033[0m"


##=-  Files -=##

FILES =					main			\
						ft_select		\
						print_error		\
						init_list		\
						init_term		\
						actions			\
						arrow_actions	\
						mod_actions		\
						print_select	\
						int_putchar		\
						catch_sig		\
						do_termcap		\
						print_header	\
						padding_control	\


SRC := $(addprefix srcs/,$(addsuffix .c,$(FILES)))
OBJ := $(addprefix obj/,$(addsuffix .o,$(FILES)))


##=-  Process -=##

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo $(GREEN) "Compiling $@" $(EOC)
	@$(CC) $(SRC) $(LFLAGS) $(IFLAGS) $(CFLAGS) -o $(NAME)

$(LIB):
	@make -C libft

obj/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@echo $(GREEN) "Remove .o  [ft_select]" $(EOC)
	@make -C ./libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo $(GREEN) "Remove all [ft_select]" $(EOC)
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re