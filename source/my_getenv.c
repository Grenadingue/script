/*
** default_shell.c for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Thu Feb 20 13:01:29 2014 Nicolas Chauvin
** Last update Fri May  1 20:45:31 2015 Nicolas Chauvin
*/

#include <stdlib.h>
#include <string.h>

static char	*get_value(char *str)
{
  char		*val;
  int		i;

  i = 0;
  val = NULL;
  while (str && str[i] && str[i - 1] != '=')
    ++i;
  if (str && str[i])
    val = &str[i];
  return (val);
}

char		*my_getenv(char **envp, char *name)
{
  char		*shell;
  int		i;

  i = 0;
  shell = NULL;
  while (name && envp && envp[i] && !shell)
    {
      if ((strncmp(envp[i], name, strlen(name))) == 0)
	shell = get_value(envp[i]);
      ++i;
    }
  return (shell);
}
