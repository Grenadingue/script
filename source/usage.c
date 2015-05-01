/*
** usage.c for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Wed Feb 19 17:17:59 2014 Nicolas Chauvin
** Last update Fri May  1 22:22:41 2015 Nicolas Chauvin
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usage.h"
#include "usage_stuffs.h"

static t_uparse	*put_args_in_list(int ac, char **av)
{
  t_uparse	*prev;
  t_uparse	*cur;
  int		i;

  i = 1;
  cur = NULL;
  prev = NULL;
  while (av && ac != i)
    {
      cur = NULL;
      if (!(cur = malloc(sizeof(t_uparse))))
	return (NULL);
      memset(cur, 0, sizeof(t_uparse));
      cur->str = av[i++];
      cur->prev = prev;
      if (prev)
	prev->next = cur;
      prev = cur;
    }
  while (cur && cur->prev)
    cur = cur->prev;
  return (cur);
}

static void	tokenize_args_list(t_uparse *uparse)
{
  while (uparse)
    {
      if (((strcmp(uparse->str, APPEND1)) == 0) ||
	  ((strcmp(uparse->str, APPEND2)) == 0))
	uparse->token = TOKEN_APPEND;
      else if (((strcmp(uparse->str, COMMAND1)) == 0) ||
	       ((strcmp(uparse->str, COMMAND2)) == 0))
	uparse->token = TOKEN_COMMAND;
      else if (((strcmp(uparse->str, FORCE1)) == 0) ||
	       ((strcmp(uparse->str, FORCE2)) == 0))
	uparse->token = TOKEN_FORCE;
      else if (((strcmp(uparse->str, VERSION1)) == 0) ||
	       ((strcmp(uparse->str, VERSION2)) == 0))
	uparse->token = TOKEN_VERSION;
      else if (((strcmp(uparse->str, HELP1)) == 0) ||
	       ((strcmp(uparse->str, HELP2)) == 0))
	uparse->token = TOKEN_HELP;
      else
	uparse->token = TOKEN_OTHER;
      uparse = uparse->next;
    }
}

static int	parse_usage(t_uparse *uparse, t_usage *usg)
{
  while (uparse)
    {
      if (uparse->token == TOKEN_VERSION || uparse->token == TOKEN_HELP)
	usg->quit = true;
      if (uparse->token == TOKEN_APPEND && !usg->append)
	usg->append = true;
      else if (uparse->token == TOKEN_COMMAND && !usg->command && uparse->next)
	{
	  usg->command = uparse->next->str;
	  uparse = uparse->next;
	}
      else if (uparse->token == TOKEN_FORCE && !usg->f_link)
	usg->f_link = true;
      else if (uparse->token == TOKEN_VERSION)
	return (1);
      else if (uparse->token == TOKEN_HELP)
	return (2);
      else if (uparse->token == TOKEN_OTHER && !usg->file)
      	usg->file = uparse->str;
      else
	return (-1);
      uparse = uparse->next;
    }
  return (0);
}

static void	free_t_uparse(t_uparse *cur)
{
  t_uparse	*next;

  next = NULL;
  while (cur)
    {
      next = cur->next;
      free(cur);
      cur = next;
    }
}

t_usage		*usage(int ac, char **av)
{
  t_uparse	*uparse;
  t_usage	*usg;
  int		ret;

  ret = 0;
  usg = NULL;
  uparse = NULL;
  if (!(usg = malloc(sizeof(t_usage))))
    return (NULL);
  memset(usg, 0, sizeof(t_usage));
  if (!(uparse = put_args_in_list(ac, av)) && ac > 1)
    return (NULL);
  tokenize_args_list(uparse);
  if ((ret = parse_usage(uparse, usg)) == -1)
    {
      fprintf(stderr, "script: invalid option(s)\n%s", HELP_MSG);
      free(usg);
      usg = NULL;
    }
  else if (ret == 1)
    printf("%s", VERSION_MSG);
  else if (ret == 2)
    printf("%s", HELP_MSG);
  free_t_uparse(uparse);
  return (usg);
}
