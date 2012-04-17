/*
** cli_pwd.c for pwd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:18:06 2012 jules1 dourlens
** Last update Thu Mar 29 20:14:20 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_pwd(t_context *c, t_request *r)
{
  unsigned int	re;
  int		ri;
  t_answer	a;
  char		buffer[20];

  re = 0;
  r->type = R_PWD;
  xwrite(c->socket, r, sizeof(*r));
  cli_xread(c->socket, &a, sizeof(a));
  while (re < a.len)
    {
      ri = cli_xread(c->socket, buffer, sizeof(buffer) - 1);
      buffer[ri] = '\0';
      re += ri;
      printf("%s", buffer);
    }
}
