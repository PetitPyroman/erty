/*
** serv_cd.c for serv_cd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 10:47:15 2012 jules1 dourlens
** Last update Tue Mar 27 11:24:17 2012 jules1 dourlens
*/

#include	"header.h"

void		serv_cd(t_context *c, t_request *r)
{
  t_answer      a;
  char		old[255];

  getcwd(old, 255);
  printf("%i: doing a cd to %s\n", c->id, r->param);
  a.len = 2;
  if (chdir(r->param))
    {
      perror("chdir");
      a.len = -1;
    }
  else
    {
      if (-1 == check_currentdir(c, strdup(old)))
	{
	  chdir(old);
	  a.len = -1;
	}
    }
  xwrite(c->socket, &a, sizeof(a));
}
