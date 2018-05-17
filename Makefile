##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

GCC		= gcc

RM		= rm -rf

CPPFLAGS	= -I./header

CFLAGS		+= -W -Wall -Werror -Wextra

NAME		= philo

SRCS		= src/check_param.c \
		  src/init_philosopher.c \
		  src/actions.c \
		  src/main.c \
		  src/sllc.c


OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) -L. -lriceferee -lpthread

clean:
	$(RM) $(OBJS)
	$(RM) *.o
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
