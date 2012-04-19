/*
** command_join.c for command_join.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 23:18:31 2012 maxime demouchy
** Last update Thu Apr 19 16:55:36 2012 maxime demouchy
*/

#include	"header.h"
#include	"server.h"

void		check_data_join_chan(t_receive *r, t_context *c, t_packet *p)
{
  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (strlen(r->packet.data) < 3 || strlen(r->packet.data) >= LEN_NAME / 2)
    strcpy(p->data, "Please enter a login >= 3 && < 32\n");
  else
    {
      p->type = ANSWER_OK;
      
    }
  
}
