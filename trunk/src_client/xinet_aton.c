/*
** xinet_aton.c for x_inte in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr  6 11:24:02 2012 jules1 dourlens
** Last update Wed Apr 18 16:07:14 2012 jules1 dourlens
*/

#include	<stdio.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"header.h"

void		xinet_aton(const char *cp, struct in_addr *inp)
{
  int		i;

  i = inet_aton(cp, inp);
  if (i == 0)
    {
      perror("inet_aton");
      exit(1);
    }
}
