/*
** server.h for server.h in /home/emax/Development/my_ftp/server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr  5 15:58:35 2012 maxime demouchy
** Last update Tue Apr 17 20:01:14 2012 maxime demouchy
*/

#ifndef		__SERVER__
#define		__SERVER__

#include	<arpa/inet.h>

#define	LEN_NAME	255

typedef	struct	s_user
{
  char		name[LEN_NAME];
  int		socket;
  struct s_user	*next;
}		t_user;

typedef struct	s_context
{
  struct sockaddr_in	server;
  int			s_socket;
  int			run;
  t_user		*users;
}		t_context;



/*
** XERROR
*/

void		xlisten(int sockfd, int backlog);
void		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen);
void		perror(const char *s);

/*
** USERS_UTILS.c
*/

t_user		*user_new(char *name, int socket);
void		user_add(t_user **u, char *name, int socket);
void		user_delete(t_user *u, char *name);

#endif
