/*
** pty_functions.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Sun Feb 23 16:17:46 2014 Nicolas Chauvin
** Last update Mon Feb 24 20:21:52 2014 nicolas chauvin
*/

#define _GNU_SOURCE
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <grp.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "v_functions.h"

static int	my_grantpt(char *pts_name)
{
  struct group	*grp;
  uid_t		uid;

  uid = getuid();
  if (!(grp = v_getgrnam("tty")))
    return (-1);
  if ((v_chmod(pts_name, 00620)) == -1)
    return (-1);
  if ((v_chown(pts_name, uid, grp->gr_gid)) == -1)
    return (-1);
  return (0);
}

static int	my_unlockpt(int ptm)
{
  int		unlock;

  unlock = 0;
  if (ioctl(ptm, TIOCSPTLCK, &unlock))
    {
      fprintf(stderr, "Error %d: ioctl() failure\n", errno);
      return (-1);
    }
  return (0);
}

static int	my_openpty(int *ptm, int *pts)
{
  char		pts_name[PATH_MAX];

  memset(pts_name, 0, PATH_MAX);
  if (((*ptm) = v_open("/dev/ptmx", O_RDWR)) == -1)
    return (-1);
  if ((ptsname_r((*ptm), pts_name, sizeof(pts_name))) == -1)
    return (-1);
  if ((my_grantpt(pts_name)) == -1)
    {
      fprintf(stderr, "Error: my_grantpt() failure\n");
      return (-1);
    }
  if ((my_unlockpt(*ptm)) == -1)
    {
      fprintf(stderr, "Error: my_unlockpt() failure\n");
      return (-1);
    }
  if (((*pts) = v_open(pts_name, O_RDWR)) == -1)
    return (-1);
  return (0);
}

int			my_forkpty(int *ptm, int *pts)
{
  if ((my_openpty(ptm, pts)) == -1)
    {
      fprintf(stderr, "Error: my_openpty() failure\n");
      return (-1);
    }
  return (fork());
}
