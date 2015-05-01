##
## Makefile for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
## 
## Made by Nicolas Chauvin
## Login   <chauvi_n@epitech.net>
## 
## Started on  Wed Feb 19 17:01:52 2014 Nicolas Chauvin
## Last update Fri May  1 20:34:16 2015 Nicolas Chauvin
##

NAME		= my_script

CC		= gcc

RM		= rm -f

SOURCE		= source/

SRCS		= $(SOURCE)main.c		\
		  $(SOURCE)v_functions1.c	\
		  $(SOURCE)v_functions2.c	\
		  $(SOURCE)my_getenv.c		\
		  $(SOURCE)usage.c		\
		  $(SOURCE)pty_functions.c	\
		  $(SOURCE)manage_ptm_pts.c	\
		  $(SOURCE)write_script_infos.c	\
		  $(SOURCE)termattr.c

OBJS		= $(SRCS:.c=.o)

HEADERS		= -I $(SOURCE)include/

CFLAGS		= -W -Wall -Wextra -Werror $(HEADERS)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
