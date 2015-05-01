/*
** v_functions.h for script
**
** Made by nicolas chauvin
** Email <chauvin.nico@gmail.com>
**
** Started on  Mon Feb 24 18:45:57 2014 nicolas chauvin
** Last update Fri May  1 20:46:15 2015 Nicolas Chauvin
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
