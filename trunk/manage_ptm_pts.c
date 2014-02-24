/*
** manage_ptm_pts.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Sun Feb 23 16:31:02 2014 Nicolas Chauvin
** Last update Mon Feb 24 20:30:20 2014 nicolas chauvin
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include "my_getenv.h"
#include "usage.h"
#include "write_script_infos.h"
#include "v_functions.h"

static int	loop_ptm(int ptm, int file, fd_set fds)
{
  fd_set	copy;
  char		buf[4096];
  int		ret;

  while (42)
    {
      copy = fds;
      if ((v_select((ptm + 1), &copy, NULL, NULL, NULL)) == -1)
	return (-1);
      if (FD_ISSET(0, &copy))
      	{
      	  if ((ret = read(0, buf, sizeof(buf))) <= 0)
	    return (-1);
	  (void)write(ptm, buf, ret);
      	}
      if (FD_ISSET(ptm, &fds))
	{
	  if ((ret = read(ptm, buf, sizeof(buf))) <= 0)
	    return (0);
	  (void)write(1, buf, ret);
	  (void)write(file, buf, ret);
	}
    }
}

static int	is_link(char *filename, t_usage *usg)
{
  struct stat	buf;

  if ((lstat(filename, &buf)) != -1 && !usg->f_link && S_ISLNK(buf.st_mode))
    {
      fprintf(stderr, "my_script: output file `%s` is a link.\n"
	      "Use -f or --force if you really want to use it.\n"
	      "Program not started.\n", filename);
      return (1);
    }
  return (0);
}

int		manage_ptm(int ptm, int pts, t_usage *usg)
{
  fd_set	fds;
  int		file;
  int		ret;

  ret = 0;
  file = 0;
  close(pts);
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  FD_SET(ptm, &fds);
  if (is_link(usg->file ? usg->file : "typescript", usg))
    return (-1);
  if ((file = open(usg->file ? usg->file : "typescript",
		   O_WRONLY | O_CREAT | (usg->append ? O_APPEND : O_TRUNC),
		   00644)) == -1)
    {
      fprintf(stderr, "Error %d: open() failure\n", errno);
      return (-1);
    }
  write_script_started(file, usg);
  ret = loop_ptm(ptm, file, fds);
  write_script_done(file, usg);
  return (ret);
}

int		manage_pts(int ptm, int pts, t_usage *usg, char **envp)
{
  char		*shell;

  shell = NULL;
  close(ptm);
  setsid();
  if ((ioctl(pts, TIOCSCTTY, NULL)) == -1)
    {
      fprintf(stderr, "Error %d: ioctl() failure\n", errno);
      return (-1);
    }
  if ((dup2(pts, 0)) == -1)
    return (-1);
  if ((dup2(pts, 1)) == -1)
    return (-1);
  if ((dup2(pts, 2)) == -1)
    return (-1);
  close(pts);
  shell = my_getenv(envp, "SHELL");
  shell = shell ? shell : "/bin/sh";
  if (!usg->command)
    execle(shell, shell, (char*)0, envp);
  else
    execle(shell, shell, "-c", usg->command, (char*)0, envp);
  fprintf(stderr, "Error %d: execle() failure\n", errno);
  return (-1);
}
