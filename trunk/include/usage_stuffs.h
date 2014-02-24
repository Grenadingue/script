/*
** usage_stuffs.h for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet
** 
** Made by Nicolas Chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Wed Feb 19 17:31:16 2014 Nicolas Chauvin
** Last update Thu Feb 20 12:47:16 2014 Nicolas Chauvin
*/

#ifndef		USAGE_STUFFS_H_
# define	USAGE_STUFFS_H_

typedef struct		s_uparse
{
  char			*str;
  int			token;
  struct s_uparse	*next;
  struct s_uparse	*prev;
}			t_uparse;

# define APPEND1	"-a"
# define APPEND2	"--append"
# define COMMAND1	"-c"
# define COMMAND2	"--command"
# define FORCE1		"-f"
# define FORCE2		"--force"
# define VERSION1	"-V"
# define VERSION2	"--version"
# define HELP1		"-h"
# define HELP2		"--help"

# define TOKEN_APPEND	1
# define TOKEN_COMMAND	2
# define TOKEN_FORCE	3
# define TOKEN_VERSION	4
# define TOKEN_HELP	5
# define TOKEN_OTHER	6

# define VERSION_MSG	"my_script from chauvi_n, version 1.0\n"
# define HELP_MSG	"\nUsage:\n my_script [option] [file]\n\n"	\
  "Options:\n -a, --append\t\t\tappend the output\n"			\
  " -c, --command <command>\trun command rather than interactive shell\n" \
  " -f, --force\t\t\tuse output file even when it is a link\n"		\
  " -V, --version\t\t\toutput version information and exit\n"		\
  " -h, --help\t\t\tdisplay this help and exit\n\n"

#endif		/* !USAGE_STUFFS_H_ */
