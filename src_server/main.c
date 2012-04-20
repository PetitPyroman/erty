/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Fri Apr 20 13:57:02 2012 maxime demouchy
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

void	send_response(int fd, t_packet *p)
{
  if (write(fd, p, sizeof(t_packet)) == -1)
    {

    }
}

void	check_data_receive(t_receive *r, t_context *c)
{
  t_receive	*tmp;
  t_packet	p;

  tmp = r;
  while (tmp)
    {
      p.id = r->packet.id;
      if (r->packet.type == REGISTER)
	{
	  check_data_register(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == JOIN_CHAN)
	{
	  check_data_join_chan(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == QUIT_CHAN)
	{
	  check_data_quit_chan(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == LIST_CHAN)
	{
	  check_data_list_chan(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == LIST_USERS)
	{
	  check_data_list_user(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == SEND_MESSAGE)
	{
	  check_data_send_message(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else if (r->packet.type == SEND_FILE)
	{
	  check_data_send_file(r, c, &p);
	  send_response(r->user_from->socket, &p);
	}
      else
	{
	  p.type = ANSWER_NO;
	  strcpy(p.data, "BAD COMMAND !\n");
	  send_response(r->user_from->socket, &p);
	}
      printf("Data Receive by : %s   type packet : %i  data : %s\n", r->user_from->name, r->packet.type, r->packet.data);
      tmp = tmp->next;
    }
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
      check_client_disconnect(c);
      check_data_receive(r, c);
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
