/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Wed Apr 18 16:39:00 2012 jules1 dourlens
*/

#include	<stdio.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<sys/socket.h>
#include	<string.h>
#include	"header.h"
#include	"client.h"
#include	"common.h"

static void	init_client(char **argv, t_context *c)
{
  c->run = 1;
  c->socket = xsocket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  xinet_aton(argv[1], &(c->server.sin_addr));
  c->server.sin_port = htons(atoi(argv[2]));
  xconnect(c->socket, (struct sockadd *) &(c->server), sizeof(c->server));
}

static void	dispatch_input(t_context *c, char *input)
{
  t_packet	packet;

  bzero(&packet, sizeof(packet));
  packet.type = REGISTER;
  strcpy(packet.data, input); 
  printf("Writted %i\n", write(c->socket, &packet, sizeof(packet)));
}

static void	do_input(t_context *c)
{
  char		input[255];

  while (c->run && fgets(input, sizeof(input), stdin))
    {
      printf("Input : %s\n", input);
      dispatch_input(c, input);
    }
}

int		main(int argc, char **argv)
{
  t_context	c;

  if (argc == 3)
    {
      init_client(argv, &c);
      do_input(&c);
    }
  else
    {
      printf("Usage: ./client IP PORT\n");
    }
  return (0);
}
