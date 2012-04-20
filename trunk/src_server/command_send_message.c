/*
** command_send_message.c for command_send_message.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr 19 17:39:11 2012 maxime demouchy
** Last update Fri Apr 20 15:38:59 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

int	send_single_people_message(t_user *u, char *name)
{
  while (u)
    {
      if (!(strcmp(u->name, name)))
	return (u->socket);
      u = u->next;
    }
  return (-1);
}

void		send_message(int fd_dest, char *data, char *msg_from)
{
  t_packet	p;

  bzero(&p, sizeof(t_packet));
  p.time = time(NULL);
  p.type = SEND_MESSAGE;
  p.id = -1;
  strcpy(p.to, msg_from);
  memcpy(p.data, data, LEN_DATA);
  send_response(fd_dest, &p);
}

void		send_to_all(t_user *u, char *chan_name, char *data, char *msg_from)
{
  while (u)
    {
      if (u->channel && !(strcmp(u->channel->name, chan_name)))
	send_message(u->socket, data, msg_from);
      u = u->next;
    }
}

void		check_data_send_message(t_receive *r, t_context *c, t_packet *p)
{
  int	fd_single;

  p->time = time(NULL);
  p->type = ANSWER_NO;
  bzero(p->data, LEN_DATA);
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
	  send_message(fd_single, r->packet.data, r->user_from->name);
	  send_message(r->user_from->socket, r->packet.data, r->user_from->name);
	}
    }
  else
    {
      if (r->user_from->channel == NULL)
	strcpy(p->data, "Can't send message... Joint a hannel before...");
      else
	{
	  p->type = ANSWER_OK;
	  send_to_all(c->users, r->user_from->channel->name, r->packet.data, r->user_from->name);
	}
    }
}
