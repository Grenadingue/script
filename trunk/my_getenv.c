/*
** default_shell.c for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Thu Feb 20 13:01:29 2014 Nicolas Chauvin
** Last update Mon Feb 24 19:47:09 2014 nicolas chauvin
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
