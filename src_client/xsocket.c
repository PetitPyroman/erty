/*
** xsocket.c for xsocket in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr  6 10:52:47 2012 jules1 dourlens
** Last update Wed Apr 18 16:02:22 2012 jules1 dourlens
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
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
