/*
** cli_get.c for cli_get in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:51:22 2012 jules1 dourlens
** Last update Fri Apr  6 19:47:21 2012 jules1 dourlens
*/

#include	"header.h"

inline static void	get_trash(char buffer[20], t_context *c, int *ri,
			       unsigned int *re)
{
  int			i;

  (void) ri;
  i = 0;
  i = cli_xread(c->socket, buffer, sizeof(buffer) - 1);
  my_uncrypt(buffer, i);
  buffer[i] = '\0';
  *re += i;
}

inline static void	get_very_trash(int *ri, unsigned int *re, t_request *r)
{
  *re = 0;
  *ri = 1;
  r->type = R_GET;
}

void			cli_get(t_context *c, t_request *r)
{
  unsigned int	re;
  int		ri;
  t_answer	a;
  char		buffer[20];
  char		*tmp;
  FILE		*f;

  get_very_trash(&ri, &re, r);
  if (!(tmp = safe_tok()))
    return;
  strcpy(r->param, tmp);
  xwrite(c->socket, r, sizeof(*r));
  cli_xread(c->socket, &a, sizeof(a));
  if (-1 == (int) a.len)
    printf("Error while getting file: Exists or permission?\n");
  else
    {
      f = fopen(r->param, "w");
      while (re < a.len)
	{
	  get_trash(buffer, c, &ri, &re);
	  fprintf(f, "%s", buffer);
	}
      fclose(f);
    }
}
