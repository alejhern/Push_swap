# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:50:18 by alejhern          #+#    #+#              #
#    Updated: 2025/01/08 00:10:02 by alejhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft/

SRCS = main.c \
       ps_stack_utils.c \
       ps_moves.c \
       ps_pushes.c \
       ps_sort_utils.c \
       ps_simple_sort.c \
       ps_turk_sort.c \
       ps_rotates.c \
       ps_rotates_reverse.c \
       ps_swapers.c \
       ps_utils.c

SRCS_B = checker.c	\
	ps_stack_utils.c	\
	ps_moves.c	\
	ps_pushes.c	\
	ps_rotates.c	\
	ps_rotates_reverse.c	\
	ps_swapers.c

OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)libft.a

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIB_DIR)" ]; then \
		git clone https://github.com/alejhern/libft.git $(LIB_DIR); \
	fi
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                BONUS                                         #
# **************************************************************************** #

bonus: $(CHECKER)

$(CHECKER): $(OBJ_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B) -L$(LIB_DIR) -lft -o $(CHECKER)
