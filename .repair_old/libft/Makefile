# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:46:16 by hmori             #+#    #+#              #
#    Updated: 2025/01/29 14:19:28 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
FLAGS			=	-Iinclude

MAKEFLAGS		+=	--no-print-directory

INCLUDE			=	include/libft.h
EXTRA_INCLUDE	=	include/get_next_line.h

SRC_DIR			=	src
SRC_FILES		=	ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c	ft_isprint.c\
					ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c\
					ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c\
					ft_strtrim.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c\
					ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c\
					ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
					ft_putbit.c ft_isspace.c ft_isvalue.c ft_split_toi.c
#					ft_spplit.c

BONUS_SRC_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

EXTRA_SRC_FILES	=	get_next_line.c

OBJ_DIR			=	obj
OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
BONUS_OBJ_FILES	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(BONUS_SRC_FILES))
EXTRA_OBJ_FILES	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(EXTRA_SRC_FILES))

NAME = libft.a

ifeq ($(flag),2)
TARGET_OBJ		=	$(OBJ_FILES) $(BONUS_OBJ_FILES) $(EXTRA_OBJ_FILES)
TARGET_INCLUDE	=	$(INCLUDE) $(EXTRA_INCLUDE)
else ifeq ($(flag),1)
TARGET_OBJ		=	$(OBJ_FILES) $(BONUS_OBJ_FILES)
TARGET_INCLUDE	=	$(INCLUDE)
else
TARGET_OBJ		=	$(OBJ_FILES)
TARGET_INCLUDE	=	$(INCLUDE)
endif

all: $(NAME)

$(NAME): $(TARGET_OBJ) $(TARGET_INCLUDE)
	ar rcs $@ $(TARGET_OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(FLAGS) -c $< -o $@

bonus:
	@$(MAKE) all flag=1

extra:
	@$(MAKE) all flag=2

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus
