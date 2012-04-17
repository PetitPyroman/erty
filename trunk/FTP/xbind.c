/*
** xbind.c for xbind in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 15:56:22 2012 jules1 dourlens
** Last update Thu Apr  5 15:58:05 2012 jules1 dourlens
*/

#include	"header.h"

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
