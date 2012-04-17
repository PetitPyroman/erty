/*
** serv_exit.c for ser_exit in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:04:20 2012 jules1 dourlens
** Last update Mon Mar 26 17:05:11 2012 jules1 dourlens
*/

#include	"header.h"

void		serv_exit(t_context *c)
{
  printf("%i: will now log out.\n", c->id);
  c->run = 0;
}
