/*
** v_functions2.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet/trunk
** 
** Made by nicolas chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Mon Feb 24 19:49:42 2014 nicolas chauvin
** Last update Mon Feb 24 20:00:10 2014 nicolas chauvin
*/

#include <errno.h>
#include <stdio.h>
#include "v_functions.h"

int	v_tcgetattr(int fd, struct termios *termios_p)
{
  if ((tcgetattr(fd, termios_p)) == -1)
    {
      fprintf(stderr, "Error %d: tcgetattr() failure\n", errno);
      return (-1);
    }
  return (0);
}

int	v_tcsetattr(int fd, int optional_actions, const struct termios *termios_p)
{
  if ((tcsetattr(fd, optional_actions, termios_p)) == -1)
    {
      fprintf(stderr, "Error %d: tcsetattr() failure\n", errno);
      return (-1);
    }
  return (0);
}
