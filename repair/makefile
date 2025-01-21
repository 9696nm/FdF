CC			=	cc
LIBX_FLAGS	=	-lXext -lX11
# LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm
LEAK		=	-fsanitize=leak
CFLAGS		=	-Iinclude
# CFLAGS		=	-Wall -Wextra -Werror -Iinclude

NAME		=	fdf

INCLUDE		=	include/fdf.h
SRC_DIR		=	src
SRC_FILES	=	main.c
OBJ_DIR 	=	obj

LIBFT		=	libft
LIBFTA		=	$(LIBFT)/libft.a

LIBMLXA		=	libmlx/libmlx_Linux.a

OBJS 		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFTA) $(INCLUDE)
	$(CC) $(LEAK) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBMLXA) -o $@ $(LIBX_FLAGS)

# $(NAME):	$(OBJS) $(LIBFTA)
# 	$(CC) $(LEAK) $^ $(LIBX_FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/ extra

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re $(LIBFT)
