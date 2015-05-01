/*
** termattr.c for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Sun Feb 23 16:30:06 2014 Nicolas Chauvin
** Last update Fri May  1 20:45:34 2015 Nicolas Chauvin
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
