/*
** server.h for server.h in /home/emax/Development/my_ftp/server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr  5 15:58:35 2012 maxime demouchy
** Last update Wed Apr 18 14:43:52 2012 maxime demouchy
*/

#ifndef		__SERVER__
#define		__SERVER__

#include	<arpa/inet.h>
#include	<sys/select.h>
#include	"header.h"

typedef struct		s_channel
{
  int			id_channel;
  char			name[LEN_NAME];
  struct s_channel	*next;
}			t_channel;

typedef	struct	s_user
{
  char		name[LEN_NAME];
  int		socket;
  t_channel	*channel;
  struct s_user	*next;
}		t_user;

typedef struct	s_context
{
  struct sockaddr_in	server;
  struct timeval	time;
  fd_set		fd_read;
  fd_set		fd_write;
  int			s_socket;
  int			run;
  t_user		*users;
}		t_context;

/*
** utils_select.c
*/

void	init_select(t_context *c);
int	get_max_fd(t_context *c);

/*
** init_server.c
*/

void	init_server(t_context *c, int port);

/*
** XERROR
*/

void		xlisten(int sockfd, int backlog);
void		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen);
void		perror(const char *s);

/*
** channel_utils.c
*/

void		channel_delete(t_channel *c, int id);
void		channel_add(t_channel **c, char *name, int id_chan);

/*
** USERS_UTILS.c
*/

void		user_add(t_user **u, char *name, int socket);
void		user_delete(t_user *u, char *name);

#endif
