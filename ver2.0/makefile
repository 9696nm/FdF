# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:14:11 by hana/hmori        #+#    #+#              #
#    Updated: 2025/02/17 11:56:15 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
FLAGS		=	-I$(INC_DIR) -I$(MLX_DIR)
CFLAGS		=	-Wall -Wextra -Werror
LIBX_FLAGS	=	-Imlx -lXext -lX11 -lm

MAKEFLAGS	+=	--no-print-directory

NAME		=	fdf

INC_DIR		=	include
INCLUDE		=	$(INC_DIR)/fdf.h

SRC_DIR		=	src
SRC_FILES	=	fdf.c graphic.c hook.c quaternion.c value_set.c unit.c q_rsqrt.c

OBJ_DIR 	=	obj
OBJS 		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

DEPENDENCY	=	$(patsubst %.c, $(OBJ_DIR)/%.d, $(SRC_FILES))

LIBFT		=	libft
LIBFTA		=	$(LIBFT)/libft.a

MLX_DIR		=	libmlx
LIBMLXA		=	$(MLX_DIR)/libmlx_Linux.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(FLAGS) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBMLXA) -o $@ $(LIBX_FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDENCY)

$(LIBFT):
	@make -C libft/ extra

bonus: all

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re:	fclean all

.DEFAULT_GOAL := all

.PHONY:	all clean fclean re $(LIBFT)
