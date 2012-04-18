/*
** init_server.c for init_server.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 00:35:03 2012 maxime demouchy
** Last update Wed Apr 18 23:17:21 2012 maxime demouchy
*/

#include	<sys/time.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

void	init_server(t_context *c, int port)
{
  c->run = 1;
  c->users = NULL;
  c->channel = NULL;
  c->s_socket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  c->server.sin_addr.s_addr = htonl(INADDR_ANY);
  c->server.sin_port = htons(port);
  xbind(c->s_socket, (struct sockaddr *) &(c->server), sizeof(c->server));
  xlisten(c->s_socket, 50);
}
