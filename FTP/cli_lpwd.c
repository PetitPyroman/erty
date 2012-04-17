/*
** cli_lpwd.c for lpwd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 10:32:58 2012 jules1 dourlens
** Last update Wed Apr  4 15:32:22 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_lpwd(t_context *c)
{
  char		buff[255];

  (void) c;
  getcwd(buff, 255);
  printf("%s\n", buff);
}
