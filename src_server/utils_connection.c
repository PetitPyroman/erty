/*
** utils_connection.c for utils_connection.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sat Apr 21 10:53:50 2012 maxime demouchy
** Last update Sat Apr 21 11:03:55 2012 maxime demouchy
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"header.h"
#include	"server.h"
#include	"common.h"

t_receive	*check_data_all_client(t_context *c)
{
  t_user	*u;
  t_receive	*r;
  int		rt;

  u = c->users;
  r = NULL;
  while (u)
    {
      if (FD_ISSET(u->socket, &(c->fd_read)))
	{
	  r = add_node_receive(r, u);
	  rt = read(u->socket, &(get_last(r)->packet), sizeof(t_packet));
	  if (rt == -1 || rt == 0)
	    {
	      u->kill = 1;
	      r = delete_last_node(r);
	      printf("user -> [%s] Disconnect\n", u->name);
	    }
	}
      u = u->next;
    }
  return (r);
}

void	check_client_disconnect(t_context *c)
{
  t_user	*u;

  u = c->users;
  while (u)
    {
      if (u->kill)
	{
	  c->users = user_delete(c->users, u);
	  u = c->users;
	}
      else
	u = u->next;
    }
}

void	send_response(int fd, t_packet *p)
{
  if (write(fd, p, sizeof(t_packet)) == -1)
    write(2, "Error write\n", 12);
}
