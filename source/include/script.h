/*
** script.h for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Sun Feb 23 16:38:20 2014 Nicolas Chauvin
** Last update Fri May  1 20:48:00 2015 Nicolas Chauvin
*/

#ifndef		SCRIPT_H_
# define	SCRIPT_H_

int	my_forkpty(int *, int *);
int	manage_ptm(int, int, t_usage *);
int	manage_pts(int, int, t_usage *, char **);

#endif		/* !SCRIPT */
