/*
** xfork.c for xfork in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 16:23:17 2012 jules1 dourlens
** Last update Thu Apr  5 16:45:12 2012 jules1 dourlens
*/

#include	"header.h"

pid_t		xfork(void)
{
  pid_t		tmp;

  tmp = fork();
  if (tmp == -1)
    {
      perror("fork");
      exit(1);
    }
  return (tmp);
}
