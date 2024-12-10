NAME	= minishell

SRCS	= main.c
OBJS	= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
