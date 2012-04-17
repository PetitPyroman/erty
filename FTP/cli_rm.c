/*
** cli_rm.c for cli_rm in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 16:43:02 2012 jules1 dourlens
** Last update Wed Apr  4 15:31:23 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_rm(t_context *c, t_request *r)
{
  char		*path;
  t_answer	a;

  path = strtok(NULL, " ");
  r->type = R_RM;
  if (!path)
    printf("Error : Provide a filename\n");
  else
    {
      strcpy(r->param, path);
      xwrite(c->socket, r, sizeof(*r));
      cli_xread(c->socket, &a, sizeof(a));
      if (-1 == (int) a.len)
        printf("Failed to rm (does file exits?)\n");
    }
}
