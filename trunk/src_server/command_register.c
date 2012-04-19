/*
** command_register.c for command_register.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 22:21:26 2012 maxime demouchy
** Last update Thu Apr 19 16:55:30 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

int		check_username_exist(t_user *u, char *name)
{
  while (u)
    {
      if (!(strcmp(u->name, name)))
	return (1);
      u = u->next;
    }
  return (0);
}

void		check_data_register(t_receive *r, t_context *c, t_packet *p)
{
  p->time = time(NULL);
  p->type = ANSWER_NO;
  if (strlen(r->packet.data) < 3 || strlen(r->packet.data) >= LEN_NAME / 2)
    strcpy(p->data, "Please enter a login >= 3 && < 32\n");
  else if (check_username_exist(c->users, r->packet.data))
    strcpy(p->data, "Sorry, your login its already used !\n");
  else
    {
      p->type = ANSWER_OK;
      strcpy(r->user_from->name, r->packet.data);
      strcpy(p->data, "Success, your new login is updated\n");
    }
}
