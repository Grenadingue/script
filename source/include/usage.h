/*
** usage.h for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Wed Feb 19 17:31:16 2014 Nicolas Chauvin
** Last update Fri May  1 20:46:19 2015 Nicolas Chauvin
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
