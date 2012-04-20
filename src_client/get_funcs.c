/*
** getType.c for getType in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr 18 18:41:24 2012 jules1 dourlens
** Last update Fri Apr 20 15:04:13 2012 jules1 dourlens
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
  else if (!(strcmp(s, MSG)))
    return (MSG_T);
  else if (!(strcmp(s, ACCEPT)))
    return (ACCEPT_T);
  else if (!(strcmp(s, SEND)))
    return (SEND_T);
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
