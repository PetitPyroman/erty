/*
** serv_rm.c for serv_rm in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 16:58:21 2012 jules1 dourlens
** Last update Tue Mar 27 17:05:25 2012 jules1 dourlens
*/

#include	"header.h"

void		serv_rm(t_context *c, t_request *r)
{
  t_answer	a;

  printf("%i: doing a rm of %s\n", c->id, r->param);
  a.len = 2;
  if (access(r->param, R_OK | W_OK))
    {
      perror("access");
      a.len = -1;
    }
  else
    {
      if (unlink(r->param))
	a.len = -1;
    }
  xwrite(c->socket, &a, sizeof(a));
}
