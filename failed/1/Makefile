NAME= gnl.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS=	get_next_line.c\
		get_next_line_utils.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)
$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all clean

run: all clean
	clear
	@cc main.c $(NAME)
	@./a.out

.PHONY: all clean fclean re