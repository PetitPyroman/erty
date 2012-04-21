/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Sat Apr 21 11:09:26 2012 maxime demouchy
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

void	check_data_receive(t_receive *r, t_context *c, t_packet *p)
{
  while (r)
    {
      p->time = time(NULL);
      p->id = r->packet.id;
      if (r->packet.type == REGISTER)
	check_data_register(r, c, p);
      else if (r->packet.type == JOIN_CHAN)
	check_data_join_chan(r, c, p);
      else if (r->packet.type == QUIT_CHAN)
	check_data_quit_chan(r, c, p);
      else if (r->packet.type == LIST_CHAN)
	check_data_list_chan(r, c, p);
      else if (r->packet.type == LIST_USERS)
	check_data_list_user(r, c, p);
      else if (r->packet.type == SEND_MESSAGE)
	check_data_send_message(r, c, p);
      else if (r->packet.type == SEND_FILE)
	check_data_send_file(r, c, p);
      send_response(r->user_from->socket, p);
      r = r->next;
    }
}

void	start_server(t_context *c)
{
  t_receive	*r;
  t_packet	p;

  while (c->run)
    {
      
      bzero(&p, sizeof(t_packet));
      p.type = ANSWER_NO;
      strcpy(p.to, "SERVER:");
      c->time.tv_sec = 1;
      c->time.tv_usec = 0;
      init_select(c);
      select(get_max_fd(c) + 1, &(c->fd_read), NULL, NULL, &(c->time));
      check_new_users(c);
      r = check_data_all_client(c);
      check_client_disconnect(c);
      check_data_receive(r, c, &p);
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
