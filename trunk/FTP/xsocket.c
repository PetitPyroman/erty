/*
** xsocket.c for xsocket in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr  6 10:52:47 2012 jules1 dourlens
** Last update Fri Apr  6 10:56:01 2012 jules1 dourlens
*/

#include	"header.h"

int		xsocket(int domain, int type, int protocol)
{
  int		ret;

  ret = socket(domain, type, protocol);
  if (ret == -1)
    {
      perror("socket");
      exit(1);
    }
  return (ret);
}
