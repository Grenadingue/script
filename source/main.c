/*
** main.c for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Wed Feb 19 17:08:00 2014 Nicolas Chauvin
** Last update Fri May  1 20:49:05 2015 Nicolas Chauvin
*/

#include <stdlib.h>
#include "usage.h"
#include "script.h"
#include "termattr.h"

static int	script(t_usage *usg, char **envp)
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
    ret = script(usg, envp);
  free(usg);
  return (ret);
}
