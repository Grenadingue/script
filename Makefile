##
## Makefile for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
## 
## Made by Nicolas Chauvin
## Login   <chauvi_n@epitech.net>
## 
## Started on  Wed Feb 19 17:01:52 2014 Nicolas Chauvin
## Last update Mon Feb 24 19:50:19 2014 nicolas chauvin
##

NAME		= my_script

CC		= gcc

RM		= rm -f

TRUNK		= trunk/

SRCS		= $(TRUNK)main.c		\
		  $(TRUNK)v_functions1.c	\
		  $(TRUNK)v_functions2.c	\
		  $(TRUNK)my_getenv.c		\
		  $(TRUNK)usage.c		\
		  $(TRUNK)pty_functions.c	\
		  $(TRUNK)manage_ptm_pts.c	\
		  $(TRUNK)write_script_infos.c	\
		  $(TRUNK)termattr.c

OBJS		= $(SRCS:.c=.o)

HEADERS		= -I $(TRUNK)include/

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
