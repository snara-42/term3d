NAME	:= term3d
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP

SRCS_DIR:= srcs/
SRCS	:= display.c exit.c key_handler.c key_hook.c main.c parse.c screen.c vec_iter.c vec_op.c vec_product.c vec_rotate.c zoom.c
# SRCS	:= $(shell find . -type f -name "*.c" | xargs basename)
OBJS_DIR:= objs/
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
INCLUDES:= includes/
DEPS	:= $(OBJS:.o=.d)

.PHONY	: all clean fclean re

all	: $(NAME)

-include $(DEPS)

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

$(OBJS_DIR):
	mkdir -p $@

clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

debug	: CFLAGS += -fsanitize=address -fsanitize=undefined -g3 
debug	: all
