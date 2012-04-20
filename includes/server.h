/*
** server.h for server.h in /home/emax/Development/my_ftp/server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr  5 15:58:35 2012 maxime demouchy
** Last update Fri Apr 20 13:41:53 2012 maxime demouchy
*/

#ifndef		__SERVER__
#define		__SERVER__

#include	<arpa/inet.h>
#include	<sys/select.h>
#include	"header.h"

typedef struct		s_channel
{
  char			name[LEN_NAME];
  struct s_channel	*next;
}			t_channel;

typedef	struct	s_user
{
  char		name[LEN_NAME];
  int		socket;
  int		kill;
  t_channel	*channel;
  struct s_user	*next;
}		t_user;

typedef struct		s_receive
{
  t_packet		packet;
  t_user		*user_from;
  struct s_receive	*next;
}			t_receive;

typedef struct	s_context
{
  struct sockaddr_in	server;
  struct timeval	time;
  fd_set		fd_read;
  int			s_socket;
  int			run;
  t_user		*users;
  t_channel		*channel;
}		t_context;

/*
** send_response.c
*/

void	send_response(int fd, t_packet *p);

/*
** command_send_file.c
*/

void		check_data_send_file(t_receive *r, t_context *c, t_packet *p);
int	send_single_people_message(t_user *u, char *name);

/*
** command_join.c
*/

void		check_data_join_chan(t_receive *r, t_context *c, t_packet *p);

/*
** command_quit_channel.c
*/

void		check_data_quit_chan(t_receive *r, t_context *c, t_packet *p);

/*
** command_list_channel.c
*/

void		check_data_list_chan(t_receive *r, t_context *c, t_packet *p);

/*
** command_send_message.c
*/

void		check_data_send_message(t_receive *r, t_context *c, t_packet *p);


/*
** command_list_users.c
*/

void		check_data_list_user(t_receive *r, t_context *c, t_packet *p);

/*
** command_register.c
*/

void		check_data_register(t_receive *r, t_context *c, t_packet *p);

/*
** utils_select.c
*/

void	init_select(t_context *c);
int	get_max_fd(t_context *c);
void	check_new_users(t_context *c);

/*
** receive_utils.c
*/

t_receive	*add_node_receive(t_receive *r, t_user *u);
t_receive	*get_last(t_receive *r);
void		*free_all_receive(t_receive *r);
t_receive	*delete_last_node(t_receive *r);

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

void		channel_delete(t_channel *c, char *name);
void		channel_add(t_channel **c, char *name);

/*
** USERS_UTILS.c
*/

void		user_add(t_user **u, char *name, int socket);
t_user		*user_delete(t_user *u, t_user *del);

#endif
