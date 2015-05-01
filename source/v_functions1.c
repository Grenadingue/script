/*
** v_functions1.c for script
**
** Made by nicolas chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Mon Feb 24 18:37:13 2014 nicolas chauvin
** Last update Fri May  1 20:45:37 2015 Nicolas Chauvin
*/

#include <errno.h>
#include <stdio.h>
#include "v_functions.h"

int	v_open(const char *pathname, int flags)
{
  int	fd;

  fd = 0;
  if ((fd = open(pathname, flags)) == -1)
    fprintf(stderr, "Error %d: open() failure\n", errno);
  return (fd);
}

int	v_chmod(const char *path, mode_t mode)
{
  if ((chmod(path, mode)) == -1)
    {
      fprintf(stderr, "Error %d: chmod() failure\n", errno);
      return (-1);
    }
  return (0);
}

int	v_chown(const char *path, uid_t owner, gid_t group)
{
  if ((chown(path, owner, group)) == -1)
    {
      fprintf(stderr, "Error %d: chown() failure\n", errno);
      return (-1);
    }
  return (0);
}

struct group	*v_getgrnam(const char *name)
{
  struct group	*grp;

  grp = NULL;
  if (!(grp = getgrnam(name)))
    fprintf(stderr, "Error %d: getgrnam() failure\n", errno);
  return (grp);
}

int	v_select(int nfds, fd_set *readfds, fd_set *writefds,
		 fd_set *exceptfds, struct timeval *timeout)
{
  if ((select(nfds, readfds, writefds, exceptfds, timeout)) == -1)
    {
      fprintf(stderr, "Error %d: select() failure\n", errno);
      return (-1);
    }
  return (0);
}
