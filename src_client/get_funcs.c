/*
** getType.c for getType in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr 18 18:41:24 2012 jules1 dourlens
** Last update Thu Apr 19 16:54:49 2012 jules1 dourlens
*/

#include		<stdlib.h>
#include		<string.h>
#include		"header.h"
#include		"client.h"

/*
** Get type from cmd!
*/
int			get_type(char *s)
{
  if (s == NULL)
    return (-1);
  else if (!(strcmp(s, JOIN)))
    return (JOIN_CHAN);
  else if (!(strcmp(s, PART)))
    return (QUIT_CHAN);
  else if (!(strcmp(s, NICK)))
    return (REGISTER);
  else if (!(strcmp(s, CHAN)))
    return (LIST_CHAN);
  else if (!(strcmp(s, USERS)))
    return (LIST_USERS);
  else
    return (-2);
}

/*
** Get an id for your request!
*/
int			get_id()
{
  static int		s_id = 0;

  s_id++;
  return (s_id);
}

/*
** Get an event!
*/
t_event			*get_event(t_context *c, int c_id, int c_type)
{
  t_event		*res;

  (void) c;
  res = malloc(sizeof(res));
  if (!res)
    exit(1);
  res->id = c_id;
  res->type = c_type;
  res->next = NULL;
  return (res);
}

/*
** Return NULL if not found
*/
t_event			*get_event_by_id(t_context *c, int id)
{
  t_event		*tmp;

  tmp = c->events;
  while (tmp)
    {
      if (tmp->id = id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
