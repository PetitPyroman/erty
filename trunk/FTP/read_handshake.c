/*
** read_handshake.c for read_handshake.c in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:31:11 2012 jules1 dourlens
** Last update Mon Apr  2 13:01:37 2012 jules1 dourlens
*/

#include	"header.h"

int             read_handshake(t_context *c)
{
  t_handshake   h;
  t_answer	a;

  if (sizeof(t_handshake) == xread(c->socket, &h, sizeof(t_handshake))
      && 1 == login_user(c, &h))
    {
      a.success = 1;
      a.len = c->rights;
    }
  else
    a.success = -1;
  xwrite(c->socket, &a, sizeof(a));
  return (a.success);
}
