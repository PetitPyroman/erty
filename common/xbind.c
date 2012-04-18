/*
** xbind.c for xbind in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 15:56:22 2012 jules1 dourlens
** Last update Tue Apr 17 19:44:05 2012 maxime demouchy
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<stdlib.h>
#include	"server.h"

void		xbind(int sockfd, const struct sockaddr *addr,
			socklen_t addrlen)
{
  int		tmp;

  tmp = bind(sockfd, addr, addrlen);
  if (tmp == -1)
    {
      perror("bind");
      exit(1);
    }
}
