/*
** users_utils.c for users in /home/dourle_a/Documents/myIrc/tmp/erty
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Apr 16 18:40:10 2012 jules1 dourlens
** Last update Wed Apr 18 14:29:23 2012 maxime demouchy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

static t_user		*user_new(char *name, int socket)
{
  t_user	*res;

  res = malloc(sizeof(t_user));
  if (!res)
    {
      perror("malloc");
      exit(1);
    }
  strncpy(res->name, name, LEN_NAME - 1);
  res->next = NULL;
  res->channel = NULL;
  res->socket = socket;
  return (res);
}

void		user_add(t_user **u, char *name, int socket)
{
  t_user	*tmp;
  t_user	*res;

  if (NULL == (*u))
    *u = user_new(name, socket);
  else
    {
      tmp = *u;
      res = user_new(name, socket);
      *u = res;
      res->next = tmp;
    }
}

void		user_delete(t_user *u, char *name)
{
  t_user	*accu;
  t_user	*prev;

  accu = u;
  prev = NULL;
  while (accu)
    {
      if (!(strcmp(name, accu->name)))
	{
	  if (prev)
	    prev->next = accu->next;
	  free(accu);
	}
      prev = accu;
      accu = accu->next;
    }
}
