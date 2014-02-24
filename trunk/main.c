/*
** main.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Wed Feb 19 17:08:00 2014 Nicolas Chauvin
** Last update Mon Feb 24 19:48:21 2014 nicolas chauvin
*/

#include <stdlib.h>
#include "usage.h"
#include "my_script.h"
#include "termattr.h"

static int	my_script(t_usage *usg, char **envp)
{
  int		ptm;
  int		pts;
  int		pid;
  int		ret;
  
  pid = -1;
  if ((pid = my_forkpty(&ptm, &pts)) == -1)
    return (-1);
  else if (pid)
    {
      set_canonical();
      ret = manage_ptm(ptm, pts, usg);
      unset_canonical();
    }
  else
    ret = manage_pts(ptm, pts, usg, envp);
  return (ret);
}

int		main(int ac, char **av, char **envp)
{
  t_usage	*usg;
  int		ret;

  ret = 0;
  usg = NULL;
  if (!(usg = usage(ac, av)))
    return (-1);
  if (!usg->quit)
    ret = my_script(usg, envp);
  free(usg);
  return (ret);
}
