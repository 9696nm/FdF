CC			=	cc
LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11 -lm
LEAK		=	-fsanitize=leak

NAME		=	fdf
SRC_DIR		=	src
SRC_FILES	=	test.c
OBJ_DIR 	=	obj
LIBFT		=	libft
LIBFTA		=	$(LIBFT)/libft.a

OBJS 		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(LIBFTA)
	@$(CC) $(LEAK) $^ $(LIBX_FLAGS) -o $@ 

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
