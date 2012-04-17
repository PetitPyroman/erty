/*
** xconnect.c for xconnect in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr  6 11:20:51 2012 jules1 dourlens
** Last update Fri Apr  6 11:22:17 2012 jules1 dourlens
*/

#include	"header.h"

void		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen)
{
  int		ret;

  ret = connect(sockfd, addr, addrlen);
  if (-1 == ret)
    {
      perror("connect");
      exit(1);
    }
}
