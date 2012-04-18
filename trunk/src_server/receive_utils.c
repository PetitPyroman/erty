/*
** receive_utils.c for utils_receive.c in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 16:16:50 2012 maxime demouchy
** Last update Wed Apr 18 16:34:13 2012 maxime demouchy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

static t_receive	*receive_new(t_user *u)
{
  t_receive	*res;

  res = malloc(sizeof(t_receive));
  if (!res)
    {
    perror("malloc");
    exit(EXIT_FAILURE);
    }
  res->next = NULL;
  res->user_from = u;
  return (res);
}

t_receive	*get_last(t_receive *r)
{
  while (r->next)
    r = r->next;
  return (r);
}

t_receive	*add_node_receive(t_receive *r, t_user *u)
{
  t_receive	*tmp;

  tmp = r;
  if (r == NULL)
    return (receive_new(u));
  else
    while (tmp->next)
      tmp = tmp->next;
  tmp->next = receive_new(u);
  return (r);
}

void		*free_all_receive(t_receive *r)
{
  t_receive	*prev;

  prev = r;
  while (r)
    {
      r = r->next;
      free(prev);
      prev = r;
    }
  return (NULL);
}
