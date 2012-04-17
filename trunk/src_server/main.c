/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Wed Apr 18 00:40:47 2012 maxime demouchy
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
      user_add(&(c->users), "anonymous", accept(c->s_socket, NULL, NULL));
    }
}

void	check_data_all_client(t_context *c)
{
  t_user	*u;

  u = c->users;
  while (u)
    {
      if (FD_ISSET(u->socket, &(c->fd_read)))
	{
	  printf("Package by : %s\n", u->name);
	}
      u = u->next;
    }
}

void	start_server(t_context *c)
{
  while (c->run)
    {
      init_select(c);
      select(get_max_fd(c) + 1, &(c->fd_read), NULL, NULL, &(c->time));
      check_new_users(c);
      check_data_all_client(c);
      //display_users(c->users);
    }
}

int	main(int argc, char **argv)
{
  t_context	c;

  if (argc > 1)
    {
      c.time.tv_sec = 1;
      c.time.tv_usec = 000;
      init_server(&c, atoi(argv[1]));
      start_server(&c);
    }
  else
    printf("usage : ./server port\n");
  return (0);
}
