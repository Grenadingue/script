/*
** my_script.h for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Sun Feb 23 16:38:20 2014 Nicolas Chauvin
** Last update Sun Feb 23 21:55:58 2014 Nicolas Chauvin
*/

#ifndef		MY_SCRIPT_H_
# define	MY_SCRIPT_H_

int	my_forkpty(int *, int *);
int	manage_ptm(int, int, t_usage *);
int	manage_pts(int, int, t_usage *, char **);

#endif		/* !MY_SCRIPT */
