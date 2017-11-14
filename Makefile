##
## Makefile for  in /home/alexis/Rendu/Système_Unix/minishell2/PSU_2015_minishell2
##
## Made by Alexis
## Login   <alexis@epitech.net>
##
## Started on  Tue Apr  5 12:09:06 2016 Alexis
## Last update Tue Jun  7 11:09:43 2016 Alex
##

##		TARGETS
NAME		= ia

##		TOOLS
CC		= gcc
RM		= rm -f
ECHO		= echo -e

##		FLAGS
CFLAGS		+= -Wall -Wextra -Werror -Iincludes

LIBFLAGS	+= -lmy -L./lib/libmy.a

##		FILES
SRCS		= sources/main.c \
		  sources/get_lidar.c \
		  sources/get_speed.c \
		  sources/get_wheels.c \
		  sources/get_direction.c \
		  sources/set_speed.c \
		  sources/my_put_nbr.c \
		  lib/my_getdouble.c \
		  lib/my_getnbr.c \
		  lib/my_putchar.c \
		  lib/get_next_line.c \
		  sources/checkpoint.c \
		  sources/change_dir.c \
		  sources/check_sides.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	@$(ECHO) "\033[32mCompilation of $(NAME) : \033[32;5mdone !\033[0m"

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re lib
