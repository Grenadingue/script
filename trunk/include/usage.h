/*
** usage.h for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Wed Feb 19 17:31:16 2014 Nicolas Chauvin
** Last update Sun Feb 23 17:12:02 2014 Nicolas Chauvin
*/

#ifndef		USAGE_H_
# define	USAGE_H_

# include "t_bool.h"

typedef struct	s_usage
{
  char		*command;
  char		*file;
  t_bool	append;
  t_bool	f_link;
  t_bool	quit;
}		t_usage;

t_usage		*usage(int, char **);

#endif		/* !USAGE_H_ */
