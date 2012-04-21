/*
** getType.c for getType in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr 18 18:41:24 2012 jules1 dourlens
** Last update Sat Apr 21 14:24:01 2012 jules1 dourlens
*/

#include		<stdio.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		<sys/socket.h>
#include		<stdlib.h>
#include		<string.h>
#include		"header.h"
#include		"client.h"

void			init_client(char **argv, t_context *c)
{
  c->run = 1;
  c->socket = xsocket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  xinet_aton(argv[1], &(c->server.sin_addr));
  c->server.sin_port = htons(atoi(argv[2]));
  xconnect(c->socket, (struct sockaddr *) &(c->server), sizeof(c->server));
}

void			get_action_socket(t_context *c, t_packet *p)
{
  if (sizeof((*p)) == xread(c->socket, p, sizeof((*p))))
    {
      if (strlen(p->data))
	{
	  if (p->type == SEND_FILE && strlen(c->accept))
	    write_a_file(p, c, c->accept);
	  else
	    printf("%s %s: %s\n", p->to, ctime(&(p->time)), p->data);
	}
    }
}

/*
** Get type from cmd!
*/
int			get_type(char *s)
{
  if (s == NULL)
    return (-1);
  else if (!(strcmp(s, JOIN)))
    return (JOIN_CHAN);
  else if (!(strcmp(s, PART)))
    return (QUIT_CHAN);
  else if (!(strcmp(s, NICK)))
    return (REGISTER);
  else if (!(strcmp(s, CHAN)))
    return (LIST_CHAN);
  else if (!(strcmp(s, USERS)))
    return (LIST_USERS);
  else if (!(strcmp(s, MSG)))
    return (MSG_T);
  else if (!(strcmp(s, ACCEPT)))
    return (ACCEPT_T);
  else if (!(strcmp(s, SEND)))
    return (SEND_T);
  else if (!(strcmp(s, "/exit")))
    exit(1);
  else
    return (-2);
}

/*
** Get an id for your request!
*/
int			get_id()
{
  static int		s_id = 0;

  s_id++;
  return (s_id);
}
