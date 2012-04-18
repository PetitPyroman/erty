/*
** getType.c for getType in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr 18 18:41:24 2012 jules1 dourlens
** Last update Wed Apr 18 21:07:59 2012 jules1 dourlens
*/

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
  else
    return (-2);
}

/*
** Get an id for your request!
*/
unsigned int		get_id()
{
  static unsigned int	s_id = 0;

  s_id++;
  return (s_id);
}
