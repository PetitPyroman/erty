/*
** command_join.c for command_join.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 23:18:31 2012 maxime demouchy
** Last update Sat Apr 21 11:07:28 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

static t_channel	*get_channel(t_channel *c, char *name)
{
  while (c)
    {
      if (!(strcmp(c->name, name)))
	return (c);
      c = c->next;
    }
  return (NULL);
}

static t_channel	*create_new_channel(t_context *c, char *name)
{
  channel_add(&(c->channel), name);
  return (get_channel(c->channel, name));
}

void		check_data_join_chan(t_receive *r, t_context *c, t_packet *p)
{
  t_channel	*chan;

  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (strlen(r->packet.data) < 3 || strlen(r->packet.data) >= LEN_NAME / 2)
    strcpy(p->data, "Please enter a channel >= 3 && < 32\n");
  else
    {
      p->type = ANSWER_OK;
      if ((chan = get_channel(c->channel, r->packet.data)) == NULL)
	{
	  strcpy(p->data, "Created new channel !\n");
	  r->user_from->channel = create_new_channel(c, r->packet.data);
	}
      else
	{
	  strcpy(p->data, "Join channel !\n");
	  r->user_from->channel = chan;
	}
    }
}
