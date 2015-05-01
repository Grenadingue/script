/*
** termattr.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Sun Feb 23 16:30:06 2014 Nicolas Chauvin
** Last update Mon Feb 24 19:58:10 2014 nicolas chauvin
*/

#include "v_functions.h"

int			set_canonical()
{
  struct termios	term_s;

  if ((v_tcgetattr(0, &term_s)) == -1)
    return (-1);
  term_s.c_lflag &= ~(ICANON | ISIG | ECHO);
  if ((v_tcsetattr(0, TCSANOW, &term_s)) == -1)
    return (-1);
  return (0);
}

int			unset_canonical()
{
  struct termios	term_s;

  if ((v_tcgetattr(0, &term_s)) == -1)
    return (-1);
  term_s.c_lflag |= (ICANON | ISIG | ECHO);
  if ((v_tcsetattr(0, TCSANOW, &term_s)) == -1)
    return (-1);
  return (0);
}
