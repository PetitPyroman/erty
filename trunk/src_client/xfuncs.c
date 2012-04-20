/*
** xconnect.c for xconnect in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr  6 11:20:51 2012 jules1 dourlens
** Last update Wed Apr 18 21:04:13 2012 jules1 dourlens
*/

#include	<stdio.h>
#include	<errno.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
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