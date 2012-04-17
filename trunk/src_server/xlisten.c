/*
** xlisten.c for xlisten in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 15:59:53 2012 jules1 dourlens
** Last update Tue Apr 17 19:44:25 2012 maxime demouchy
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<stdlib.h>
#include	"server.h"

void		xlisten(int sockfd, int backlog)
{
  int		tmp;

  tmp = listen(sockfd, backlog);
  if (tmp == -1)
    {
      perror("listen");
      exit(1);
    }
}
