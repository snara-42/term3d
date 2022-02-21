NAME	:= term3d
CC		:= gcc
CFLAGS:= -Wall -Wextra -Werror

SRCS_DIR:= srcs/
SRCS	:= $(shell find . -type f -name "*.c" | xargs basename)
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
	@mkdir $@

clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all