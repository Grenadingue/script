/*
** v_functions1.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet/trunk
** 
** Made by nicolas chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Mon Feb 24 18:37:13 2014 nicolas chauvin
** Last update Mon Feb 24 19:59:58 2014 nicolas chauvin
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
