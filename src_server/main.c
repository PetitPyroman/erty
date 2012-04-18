/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Wed Apr 18 16:40:00 2012 maxime demouchy
*/

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

void	check_new_users(t_context *c)
{
  if (FD_ISSET(c->s_socket, &(c->fd_read)))
    {
      printf("New users connected !!\n");
      user_add(&(c->users), "Anonymous", accept(c->s_socket, NULL, NULL));
    }
}

t_receive	*check_data_all_client(t_context *c)
{
  t_user	*u;
  t_receive	*r;

  u = c->users;
  r = NULL;
  while (u)
    {
      if (FD_ISSET(u->socket, &(c->fd_read)))
	{
	  r = add_node_receive(r, u);
	  printf("NEW DATA INC !!!\n");
	  printf("rt == %i\n", read(u->socket, &(get_last(r)->packet), sizeof(t_packet)));
	}
      u = u->next;
    }
  return (r);
}

void	check_data_receive(t_receive *r)
{
  t_receive	*tmp;

  tmp = r;
  while (tmp)
    {
      printf("Data Receive by : %s   type packet : %i  data : %s\n", r->user_from->name, r->packet.type, r->packet.data);
      tmp = tmp->next;
    }
  return (NULL);
}

void	start_server(t_context *c)
{
  t_receive	*r;

  
  printf("%i\n", sizeof(t_packet));
  while (c->run)
    {
      c->time.tv_sec = 1;
      c->time.tv_usec = 0;
      init_select(c);
      select(get_max_fd(c) + 1, &(c->fd_read), NULL, NULL, &(c->time));
      check_new_users(c);
      r = check_data_all_client(c);
      check_data_receive(r);
      r = free_all_receive(r);
    }
}

int	main(int argc, char **argv)
{
  t_context	c;

  if (argc > 1)
    {
      
      init_server(&c, atoi(argv[1]));
      start_server(&c);
    }
  else
    printf("usage : ./server port\n");
  return (0);
}
