/*
** command_send_message.c for command_send_message.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr 19 17:39:11 2012 maxime demouchy
** Last update Fri Apr 20 13:35:35 2012 maxime demouchy
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

void		send_message(int fd_dest, char *data)
{
  t_packet	p;

  p.type = SEND_MESSAGE;
  p.id = -1;
  memcpy(p.data, data, LEN_DATA);
  send_response(fd_dest, &p);
}

void		send_to_all(t_user *u, char *chan_name, char *data)
{
  while (u)
    {
      if (!(strcmp(u->channel->name, chan_name)))
	send_message(u->socket, data);
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
	  send_message(fd_single, r->packet.data);
	  send_message(r->user_from->socket, r->packet.data);
	}
    }
  else
    {
      p->type = ANSWER_OK;
      send_to_all(c->users, r->user_from->channel->name, r->packet.data);
    }
}
