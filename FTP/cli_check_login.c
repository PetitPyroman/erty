/*
** cli_check_login.c for cli in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Apr  2 12:56:47 2012 jules1 dourlens
** Last update Mon Apr  2 12:59:27 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_check_login(t_context *c)
{
  t_answer	a;

  cli_xread(c->socket, &a, sizeof(a));
  if (a.success == 1)
    {
      printf("You're now logged!\n");
      c->rights = a.len;
    }
  else
    {
      printf("Bad username/password\n");
      close(c->socket);
      exit(1);
    }
}
