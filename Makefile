# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florian <florian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:51:14 by florian           #+#    #+#              #
#    Updated: 2024/04/16 16:12:08 by florian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
NAME_CLIENT = client
NAME_SERVER = server

# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

MAIN_CLIENT = client.c
MAIN_SERVER = server.c
SRC_CLIENT = 
SRC_SERVER = 

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRC_DIR_CLIENT = client/
SRC_DIR_SERVER = server/
OBJ_DIR = obj/
INCLUDE_DIR	= inc/
# a verifier src = srcs
SRC_CLIENT	= $(addprefix $(SRC_DIR_CLIENT), $(SRC_CLIENT))
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJS_CLIENT	= $(addprefix $(OBJ_DIR), $(OBJ_CLIENT))

SRC_SERVER	= $(addprefix $(SRC_DIR_SERVER), $(SRC_SERVER))
OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJS_SERVER	= $(addprefix $(OBJ_DIR), $(OBJ_SERVER))



MAIN_CLIENT	= $(addprefix $(SRC_DIR_SERVER), $(SRC_SERVER))
OBJ_SERVER	= $(SRC_SERVER:.c=.o)
OBJS_SERVER	= $(addprefix $(OBJ_DIR), $(OBJ_SERVER))

OBJ_MAIN  	= $(MAIN:.c=.o)
OBJS_MAIN	= $(addprefix $(OBJ_DIR), $(OBJ_MAIN))

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all : $(NAME)

bonus : $(NAME_BONUS) 

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS) $(OBJS_MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_MAIN) $(LIBFT)

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJ_DIR)%.o: $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_BONUS)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)

re : fclean all

.PHONY: all bonus clean fclean re
