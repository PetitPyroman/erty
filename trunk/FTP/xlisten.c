/*
** xlisten.c for xlisten in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 15:59:53 2012 jules1 dourlens
** Last update Thu Apr  5 16:02:00 2012 jules1 dourlens
*/

#include	"header.h"

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
