/*
** v_functions.h for my_script in /home/chauvi_n/TAF/tek2/System Unix/my_script/projet/trunk
** 
** Made by nicolas chauvin
** Login   <chauvi_n@epitech.net>
** 
** Started on  Mon Feb 24 18:45:57 2014 nicolas chauvin
** Last update Mon Feb 24 20:02:06 2014 nicolas chauvin
*/

#ifndef		V_FUNCTIONS_H_
# define	V_FUNCTIONS_H_

# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <termios.h>
# include <fcntl.h>
# include <grp.h>
# include <unistd.h>

int		v_open(const char *, int);
int		v_chmod(const char *, mode_t);
int		v_chown(const char *, uid_t, gid_t);
int		v_select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
int		v_tcgetattr(int, struct termios *);
int		v_tcsetattr(int, int, const struct termios *);
struct group	*v_getgrnam(const char *);

#endif		/* !V_FUNCTIONS_H_ */
