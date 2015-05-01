/*
** usage.h for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Wed Feb 19 17:31:16 2014 Nicolas Chauvin
** Last update Fri May  1 22:21:38 2015 Nicolas Chauvin
*/

#ifndef		USAGE_H_
# define	USAGE_H_

# include <stdbool.h>

typedef struct	s_usage
{
  char		*command;
  char		*file;
  bool		append;
  bool		f_link;
  bool		quit;
}		t_usage;

t_usage		*usage(int, char **);

#endif		/* !USAGE_H_ */
