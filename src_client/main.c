/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Thu Apr 19 16:55:43 2012 jules1 dourlens
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
  c->events = NULL;
}

/*
** How to deal with the cmd to parse! 
*/
static void	dispatch_input(t_context *c, char *input)
{
  t_packet	packet;
  char		*tmp;

  input[strlen(input) -1] = NULL;
  bzero(&packet, sizeof(packet));
  packet.type = get_type(strtok(input, DELIM));
  if (-1 == packet.type)
    return;
  else if (-2 == packet.type)
    {
      packet.type = SEND_MESSAGE;
      strncpy(packet.data, input, LEN_DATA - 1);
    }
  else if (JOIN_CHAN == packet.type || SEND_MESSAGE == packet.type || LIST_CHAN == packet.type
	   ||  LIST_USERS == packet.type ||  QUIT_CHAN == packet.type || REGISTER == packet.type)
    {
      tmp = strtok(NULL, DELIM);
      if (NULL != tmp)
	strncpy(packet.data, tmp, LEN_DATA - 1); 
    }
  packet.id = get_id();
  event_push(c, packet.id, packet.type);
  printf("Writen %i\n", write(c->socket, &packet, sizeof(packet)));
}

/*
** Select done here to get the input line from std::in
** and the socket server output!
*/
static void	do_input(t_context *c)
{
  char		input[255];
  t_packet	p;

  while (c->run)
    {
      FD_ZERO(&(c->read));
      FD_SET(c->socket, &(c->read));
      FD_SET(0, &(c->read));
      select(c->socket + 1, &(c->read), NULL, NULL, NULL);
      if (FD_ISSET(c->socket, &(c->read)))
	{
	  read(c->socket, &p, sizeof(p));
	  printf("type: %i, data: %s\n", p.type, p.data);
	}
      else if (FD_ISSET(0, &(c->read)))
	{
	  if (fgets(input, sizeof(input), stdin))
	    dispatch_input(c, input);
	  else
	    c->run = 0;
	}
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
