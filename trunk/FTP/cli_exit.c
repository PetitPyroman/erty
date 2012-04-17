/*
** exit.c for exit in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:35:28 2012 jules1 dourlens
** Last update Mon Mar 26 16:36:27 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_exit(t_context *c, t_request *r)
{
  r->type = R_EXIT;
  xwrite(c->socket, r, sizeof(*r));
  printf("Disconnect...\n");
  c->run = 0;
}
