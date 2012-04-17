/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Tue Apr 17 20:52:37 2012 maxime demouchy
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<unistd.h>

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<string.h>
#include	<arpa/inet.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"header.h"
#include	"server.h"
#include	"common.h"

static void	init_server(t_context *c, int port)
{
  c->run = 1;
  c->users = NULL;
  c->s_socket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  c->server.sin_addr.s_addr = htonl(INADDR_ANY);
  c->server.sin_port = htons(port);
  xbind(c->s_socket, (struct sockaddr *) &(c->server), sizeof(c->server));
  xlisten(c->s_socket, 50);
}

void	init_select(t_user *u)
{
  fd_set	fd_read;

  FD_ZERO(&fd_read);
  FD_SET(u->socket, &fd_read);
  
  select(u->socket + 1, &fd_read, NULL, NULL, NULL);
  
  if (FD_ISSET(u->socket, &fd_read))
    {
      printf("DATA RECEIVE !\n");
      read
    }
  else
    {
      printf("NO DATA !!!\n");
    }
}

int	get_max_fd(t_user *u)
{
  int	maxfd;

  maxfd = -1;
  while (u)
    {
      if (u->socket > maxdf)
	maxfd = u->socket;
      u = u->next;
    }
  return (maxfd);
}

void	start_server(t_context *c)
{
  while (c->run)
    {
      init_select(c);
      
      user_add(&(c->users), "LooL", accept(c->s_socket, NULL, NULL));
      if (maxfd != -1)
	init_select(c->users);
      //display_users(c->users);
    }
}

int	main(int argc, char **argv)
{
  t_context	c;

  if (argc > 1)
    {
      init_server(&c, atoi(argv[1]));
      printf("socket server = %i\n", c.s_socket);
      start_server(&c);
    }
  else
    printf("usage : ./server port");
  return (0);
}
