/*
** channel_utils.c for demouc_m in /home/emax/Development/erty/src_server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Wed Apr 18 14:13:46 2012 maxime demouchy
** Last update Thu Apr 19 17:06:33 2012 maxime demouchy
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

static t_channel	*channel_new(char *name)
{
  t_channel	*chan;

  chan = malloc(sizeof(t_channel));
  if (!chan)
    {
      perror("malloc");
      exit(EXIT_FAILURE);
    }
  strncpy(chan->name, name, LEN_NAME - 1);
  chan->next = NULL;
  return (chan);
}

void		channel_add(t_channel **c, char *name)
{
  t_channel	*tmp;
  t_channel	*res;

  if (NULL == (*c))
    *c = channel_new(name);
  else
    {
      tmp = *c;
      res = channel_new(name);
      *c = res;
      res->next = tmp;
    }
}

void		channel_delete(t_channel *c, char *name)
{
  t_channel	*chan;
  t_channel	*prev;

  chan = c;
  prev = NULL;
  while (chan)
    {
      if (!(strcmp(chan->name, name)))
	{
	  if (prev)
	    prev->next = chan->next;
	  free(chan);
	}
      prev = chan;
      chan = chan->next;
    }
}
