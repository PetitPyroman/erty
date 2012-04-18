/*
** utils_select.c for utils_select.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 00:36:35 2012 maxime demouchy
** Last update Wed Apr 18 19:05:26 2012 maxime demouchy
*/

#include	<stdio.h>
#include	"server.h"

void	check_new_users(t_context *c)
{
  if (FD_ISSET(c->s_socket, &(c->fd_read)))
    {
      printf("New users connected !!\n");
      user_add(&(c->users), "Anonymous", accept(c->s_socket, NULL, NULL));
    }
}

void	init_select(t_context *c)
{
  t_user	*u;

  u = c->users;
  FD_ZERO(&(c->fd_read));
  FD_SET(c->s_socket, &(c->fd_read));
  while (u)
    {
      FD_SET(u->socket, &(c->fd_read));
      u = u->next;
    }
}

int	get_max_fd(t_context *c)
{
  int		maxfd;
  t_user	*u;

  u = c->users;
  maxfd = c->s_socket;
  while (u)
    {
      if (u->socket > maxfd)
	maxfd = u->socket;
      u = u->next;
    }
  return (maxfd);
}
