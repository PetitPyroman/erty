/*
** client.h for client.h in /home/emax/Development/my_ftp/client
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 16:12:39 2012 maxime demouchy
** Last update Sat Apr 21 14:21:27 2012 jules1 dourlens
*/

#ifndef			__CLIENT__
#define			__CLIENT__

#include		<arpa/inet.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<stdio.h>
#include		"header.h"

/*
** Parser things
*/
#define DELIM		" "

#define JOIN		"/join"
#define PART		"/part"
#define NICK		"/nick"
#define CHAN		"/list"
#define USERS		"/users"
#define MSG		"/msg"
#define SEND		"/send_file"
#define ACCEPT		"/accept_file"

/*
** INNER Client types!
*/
#define MSG_T		145
#define ACCEPT_T	69
#define SEND_T		84

typedef struct		s_context
{
  char			accept[LEN_NAME];
  int			socket;
  struct sockaddr_in	server;
  int			run;
  fd_set		read;
}			t_context;

void			id_ok_type(t_context *c, t_packet *packet,
				   char *tmp, char *input);
int			send_a_file(t_packet *p, t_context *c, char *file);
int			write_a_file(t_packet *p, t_context *c, char *file);
void			init_client(char **argv, t_context *c);
void			get_action_socket(t_context *c, t_packet *p);
int			get_type(char *s);
int			get_id(void);
int			main(int argc, char **argv);
void			xconnect(int sockfd, struct sockaddr *addr,
				 socklen_t a);
void			xinet_aton(const char *cp, struct in_addr *inp);
int			xsocket(int domain, int type, int protocol);
ssize_t			xread(int fd, void *b, size_t count);

#endif
