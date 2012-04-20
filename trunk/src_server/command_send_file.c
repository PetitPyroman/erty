/*
** command_send_file.c for command_send_file.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Fri Apr 20 13:32:15 2012 maxime demouchy
** Last update Fri Apr 20 13:40:39 2012 maxime demouchy
*/

#include	<string.h>
#include	"header.h"
#include	"server.h"

static void	send_file(int fd, char *data, char *name_from)
{
  t_packet	p;

  bzero(&p, sizeof(t_packet));
  p.type = SEND_FILE;
  p.id = -1;
  strcpy(p.data, data);
  strcpy(p.to, name_from);
  send_response(fd, &p);
}

void		check_data_send_file(t_receive *r, t_context *c, t_packet *p)
{
  int		fd_single;

  p->time = time(NULL);
  p->type = ANSWER_NO;
  bzero(p->data, LEN_DATA);
  if (strlen(r->packet.data) == 0)
    strcpy(p->data, "Please enter file...\n");
  else if (strlen(r->packet.data) == 0)
    strcpy(p->data, "Please enter destinataire to send file...\n");
  else
    {
      fd_single = send_single_people_message(c->users, r->packet.to);
      if (fd_single == -1)
	strcpy(p->data, "Can't send message because login doesnt exist !\n");
      else
	{
	  p->type = ANSWER_OK;
	  send_file(fd_single, r->packet.data, r->user_from->name);
	}
    }
}
