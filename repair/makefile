# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:14:11 by hana/hmori        #+#    #+#              #
#    Updated: 2025/01/26 22:40:55 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
FLAGS		=	-I$(INC_DIR)
CFLAGS		=
# CFLAGS	 =	-Wall -Wextra -Werror
LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm
# LIBX_FLAGS	=	-lXext -lX11

MAKEFLAGS	+=	--no-print-directory

LEAK		=	-fsanitize=leak


NAME		=	fdf

INC_DIR		=	include
INCLUDE		=	$(INC_DIR)/fdf.h

SRC_DIR		=	src
SRC_FILES	=	fdf.c graphic.c rotate.c hook.c unit.c
# SRC_FILES	=	circle.c

OBJ_DIR 	=	obj
OBJS 		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

LIBFT		=	libft
LIBFTA		=	$(LIBFT)/libft.a

LIBMLXA		=	libmlx/libmlx_Linux.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFTA) $(INCLUDE)
	$(CC) $(LEAK) $(FLAGS) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBMLXA) -o $@ $(LIBX_FLAGS)

# $(NAME):	$(OBJS) $(LIBFTA)
# 	$(CC) $(LEAK) $^ $(LIBX_FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/ extra

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re:	fclean all

.DEFAULT_GOAL := all

.PHONY:	all clean fclean re $(LIBFT)
