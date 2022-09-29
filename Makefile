# Variables
NAME	=	graphing
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/

# Sources

SRC_FILES	=	

SRCS	=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#######

all:
		@mkdir -p $(OBJS_DIR)
		@make $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJS)
			@(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "graphing executable created!"

clean:
		@rm -rf $(OBJS_DIR)
		@echo "object files removed"

fclean:	clean
		@rm -f $(NAME)
		@echo "graphing executable removed"

re:	fclean all

.PHONY:	all clean fclean re
