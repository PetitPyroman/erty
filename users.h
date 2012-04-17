/*
** users.h for users in /home/dourle_a/Documents/myIrc/tmp/erty
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Apr 16 18:36:24 2012 jules1 dourlens
** Last update Mon Apr 16 18:43:28 2012 jules1 dourlens
*/

#ifndef		___H_USERS___
#define		___H_USERS___

#include	<stdlib.h>

#define	LEN_NAME	255

typedef	struct	s_user
{
  char		name[LEN_NAME];
  int		socket;
  struct s_user	*next;
}		t_user;

#endif
