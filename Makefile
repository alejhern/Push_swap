# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:50:18 by alejhern          #+#    #+#              #
#    Updated: 2024/09/23 17:57:24 by alejhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft/

SRCS = main.c \
       ps_moves.c \
       ps_pushes.c \
       ps_sort_utils.c \
       ps_sorters_2_5.c \
       ps_radix_sort.c \
       ps_rotates.c \
       ps_rotates_reverse.c \
       ps_swapers.c \
       ps_utils.c

OBJ = $(SRCS:.c=.o)
# OBJ_B = $(SRCS_B:.c=.o)

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME = push_swap

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
	@make -C $(LIB_DIR)

clean:
	@make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                BONUS                                         #
# **************************************************************************** #

bonus: $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME)