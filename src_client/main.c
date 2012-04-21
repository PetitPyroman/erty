/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Sat Apr 21 15:32:14 2012 maxime demouchy
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

static int	dispatch_input_(t_context *c, char *input, t_packet *packet)
{
  char		*t;

  (void) c;
  input[strlen(input) - 1] = '\0';
  bzero(packet, sizeof((*packet)));
  t = strdup(input);
  strtok(t, DELIM);
  packet->type = get_type(strtok(t, DELIM));
  free(t);
  if ((int) packet->type != -2)
    strtok(input, DELIM);
  return (1);
}

/*
** How to deal with the cmd to parse! 
*/
static void	dispatch_input(t_context *c, char *input, char *tmp, char *data)
{
  t_packet	packet;

  if (dispatch_input_(c, input, &packet) && -1 == packet.type)
    return;
  else if (ACCEPT_T == packet.type && (1 || data))
    {
      tmp = strtok(NULL, DELIM);
      bzero(c->accept, LEN_NAME);
      strncpy(c->accept, tmp, LEN_NAME -1);
      return;
    }
  else if (SEND_T == packet.type && strlen(c->accept))
    {
      tmp = strtok(NULL, DELIM);
      strncpy(packet.to, tmp, LEN_NAME -1);
      tmp = strtok(NULL, DELIM);
      packet.type = SEND_FILE;
      if (!send_a_file(&packet, c, tmp))
	return;
    }
  else
    id_ok_type(c, &packet, tmp, input);
  packet.time = time(NULL);
  packet.id = get_id();
  write(c->socket, &packet, sizeof(packet));
}

/*
** Select done here to get the input line from std::in
** and the socket server output!
*/
static void	do_input(t_context *c)
{
  char		input[LEN_DATA * 10];
  t_packet	p;

  while (c->run)
    {
      FD_ZERO(&(c->read));
      FD_SET(c->socket, &(c->read));
      FD_SET(0, &(c->read));
      select(c->socket + 1, &(c->read), NULL, NULL, NULL);
      if (FD_ISSET(c->socket, &(c->read)))
	get_action_socket(c, &p);
      else if (FD_ISSET(0, &(c->read)))
	{
	  if (fgets(input, sizeof(input), stdin))
	    {
	      dispatch_input(c, input, NULL, NULL);
	    }
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
      close(c.socket);
    }
  else
    {
      printf("Usage: ./client IP PORT\n");
    }
  return (0);
}
