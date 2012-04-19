/*
** command_list_chan.c for command_list_chan.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr 19 17:25:44 2012 maxime demouchy
** Last update Thu Apr 19 17:36:13 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

static void		create_string_list_chan(t_channel *c, char *buff)
{
  bzero(buff, LEN_DATA);
  strcpy(buff, "Channel :\n");
  while (c)
    {
      strcat(buff, c->name);
      strcat(buff, "\n");
      c = c->next;
    }
}

void		check_data_list_chan(t_receive *r, t_context *c, t_packet *p)
{
  (void)r;
  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (c->channel == NULL)
    strcpy(p->data, "No channel created in server !\n");
  else
    create_string_list_chan(c->channel, p->data);
}
