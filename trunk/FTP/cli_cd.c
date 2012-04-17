/*
** cli_cd.c for cd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 10:43:07 2012 jules1 dourlens
** Last update Wed Apr  4 16:10:48 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_cd(t_context *c, t_request *r)
{
  char		*path;
  t_answer	a;

  path = strtok(NULL, " ");
  r->type = R_CD;
  if (!path)
    printf("Error : Provide a path");
  else
    {
      strcpy(r->param, path);
      xwrite(c->socket, r, sizeof(*r));
      cli_xread(c->socket, &a, sizeof(a));
      if (-1 == (int) a.len)
	printf("Failed to change directory (do you have rights?)\n");
    }
}
