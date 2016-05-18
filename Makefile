#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguthert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 15:25:02 by jguthert          #+#    #+#              #
#    Updated: 2016/05/18 15:03:55 by jguthert         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##=-  Compilatator -=##

NAME = ft_select
CC = gcc


##=-  FLAGS -=##

CFLAGS = -Wall -Wextra -g3 #-Werror


##=-  PATH -=##

OBJPATH = obj
SRCPATH = srcs
LIBFT_PATH = libft

INCLUDE_PATH = include/

##=-  Rules -=##

LIBFT = -L $(LIBFT_PATH)
LIBS = $(LIBFT) -lft -lncurses

INCLUDES = -I./ -I $(LIBFT_PATH)/includes -I $(INCLUDE_PATH)


##=-  Files -=##

OBJ = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))

SRCSFILES =				main.c			\
						ft_select.c		\
						print_error.c	\
						init_list.c		\
						init_term.c		\
						actions.c		\
						arrow_actions.c	\
						mod_actions.c	\
						print_select.c	\
						int_putchar.c	\
						catch_sig.c		\
						do_termcap.c	\
						print_header.c	\
						padding_control.c	\

##=-  Process -=##

all: $(NAME)

$(NAME): $(OBJ)
#	@echo "\n\033[33mProcessing\n\033[0m"
	@$(MAKE) -C libft/
	@$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)
#	@echo "\n\033[33mEnd of the Process\n\033[0m"

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
#	@echo "\033[32m"
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
#	@echo "\033[0m"

clean:
	@/bin/rm -rf $(OBJPATH)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all