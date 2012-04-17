/*
** cli_ls.c for cli_ls in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:39:07 2012 jules1 dourlens
** Last update Thu Mar 29 20:13:45 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_ls(t_context *c, t_request *r)
{
  unsigned int	re;
  int		ri;
  t_answer	a;
  char		buffer[20];

  re = 0;
  r->type = R_LS;
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

void		cli_lsi(t_context *c, t_request *r)
{
  unsigned int	re;
  int		ri;
  t_answer	a;
  char		buffer[20];

  re = 0;
  r->type = R_LSI;
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
