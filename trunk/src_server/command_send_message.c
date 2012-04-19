/*
** command_send_message.c for command_send_message.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr 19 17:39:11 2012 maxime demouchy
** Last update Thu Apr 19 17:54:51 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

static int	send_single_people_message(t_user *u, char *name)
{
  while (u)
    {
      if (!(strcmp(u->name, name)))
	return (u->socket);
      u = u->next;
    }
  return (-1);
}

void		send_message(int fd, char *data)
{
  t_packet	p;

  p.type = SEND_MESSAGE;
  memcpy(p.data, data, LEN_DATA);
  send_response(fd, &p);
}

void		check_data_send_message(t_receive *r, t_context *c, t_packet *p)
{
  int	fd_single;

  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (strlen(r->packet.data) == 0)
    strcpy(p->data, "Please enter message...\n");
  else if (strlen(r->packet.to))
    {
      fd_single = send_single_people_message(c->users, r->packet.to);
      if (fd_single == -1)
	strcpy(p->data, "Can't send message because login doesnt exist !\n");
      else
	{
	  p->type = ANSWER_OK;
	  send_message(fd_single, r->packet.data);
	  strcpy(p->data, "Message successfull sending\n");
	}
    }
  else
    strcpy(p->data, "Message send to all channel not supported now...\n");
}
