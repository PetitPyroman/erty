/*
** event_manager.c for event_manager in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr 19 12:24:52 2012 jules1 dourlens
** Last update Thu Apr 19 12:35:18 2012 jules1 dourlens
*/

#include		<stdlib.h>
#include		<string.h>
#include		"header.h"
#include		"client.h"

void			event_push(t_context *c, int c_id, int c_type)
{
  t_event		*tmp;

  if (NULL == c->events)
    c->events = get_event(c, c_id, c_type);
  else
    {
      tmp = c->events;
      while (tmp->next)
	{
	  tmp = tmp->next;
	}
      tmp->next = get_event(c, c_id, c_type);
    }
}

void			event_pop(t_context *c, int id)
{
  t_event		*tmp;
  t_event		*temp;

  if (c->events)
    {
      if (c->events->id == id)
	{
	  tmp = c->events;
	  c->events = tmp->next;
	  free(tmp);
	}
      else
	{
	  tmp = c->events;
	  while (tmp->next)
	    {
	      if (tmp->next->id == id)
		{
		  temp = tmp->next;
		  tmp->next = temp->next;
		  free(temp);
		}
	      tmp = tmp->next;
	    }
	}
    }
}
