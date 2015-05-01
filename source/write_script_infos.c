/*
** write_script_infos.c for script
**
** Made by Nicolas Chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Sun Feb 23 23:31:44 2014 Nicolas Chauvin
** Last update Fri May  1 20:45:41 2015 Nicolas Chauvin
*/

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "usage.h"

static void	get_time_str(char *time_str)
{
  struct tm     *now;
  time_t	time_val;

  now = NULL;
  time_val = time(NULL);
  now = localtime(&time_val);
  strftime(time_str, 64, "%a %d %b %Y %I:%M:%S %p %Z\n", now);
}

void		write_script_started(const int file, const t_usage *usg)
{
  char		time_str[64];

  memset(time_str, 0, sizeof(time_str));
  get_time_str(time_str);
  (void)write(file, "Script started on ", strlen("Script started on "));
  (void)write(file, time_str, strlen(time_str));
  printf("Script started, file is %s\n", usg->file ? usg->file : "typescript");
}

void		write_script_done(const int file, const t_usage *usg)
{
  char		time_str[64];

  memset(time_str, 0, sizeof(time_str));
  get_time_str(time_str);
  (void)write(file, "\nScript done on ", strlen("\nScript done on "));
  (void)write(file, time_str, strlen(time_str));
  printf("Script done, file is %s\n", usg->file ? usg->file : "typescript");
}
