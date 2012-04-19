/*
** command_quit_chan.c for command_quit_chan.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr 19 17:18:30 2012 maxime demouchy
** Last update Thu Apr 19 17:30:10 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

void		check_data_quit_chan(t_receive *r, t_context *c, t_packet *p)
{
  (void)c;
  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (r->user_from->channel == NULL)
    strcpy(p->data, "You cannot QUIT channel because your are not in a channel !\n");
  else
    {
      p->type = ANSWER_OK;
      r->user_from->channel = NULL;
      strcpy(p->data, "Successfull QUIT channel !\n");
    }
}
