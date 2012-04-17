/*
** serv_put.c for serv_put in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 15:42:23 2012 jules1 dourlens
** Last update Wed Apr  4 15:34:22 2012 jules1 dourlens
*/

#include	"header.h"

void		serv_put(t_context *c, t_request *r)
{
  unsigned int  re;
  int           ri;
  char          buffer[20];
  char          *tmp;
  FILE          *f;

  re = 0;
  ri = 1;
  tmp = r->param;
  f = fopen(r->param, "w");
  if (f != NULL)
    {
      printf("%i: putting %s\n", c->id, r->param);
      while (re < r->len)
	{
	  ri = xread(c->socket, buffer, sizeof(buffer) - 1);
	  buffer[ri] = '\0';
	  my_uncrypt(buffer, ri);
	  re += ri;
	  fprintf(f, "%s", buffer);
	}
      fclose(f);
    }
}
