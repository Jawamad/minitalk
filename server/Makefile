# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florian <florian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:20:27 by florian           #+#    #+#              #
#    Updated: 2024/05/13 13:02:31 by florian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
PRINTF = ../printf/libftprintf.a
NAME = server

# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

MAIN	= server.c
SRC		= signal.c utils.c

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE_DIR	= inc/

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

OBJ_MAIN	= $(MAIN:.c=.o)
OBJS_MAIN	= $(addprefix $(OBJ_DIR), $(OBJ_MAIN))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all : $(NAME)

$(PRINTF):
	@make -C ../printf

$(NAME): $(OBJS) $(OBJS_MAIN) $(PRINTF)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_MAIN) $(PRINTF)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJ_DIR)%.o: $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)*
	@make clean -C ../printf

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
