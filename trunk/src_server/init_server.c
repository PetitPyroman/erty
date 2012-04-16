/*
** init_server.c for init_server.c in /home/emax/Development/my_ftp/server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 13:45:09 2012 maxime demouchy
** Last update Sun Apr  8 13:45:58 2012 maxime demouchy
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<netdb.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"header.h"
#include	"server.h"
#include	"common.h"

int	init_server(int port)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;

  pe = getprotobyname("TCP");
  if (!pe)
    return (-1);
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      close(s);
      return (-1);
    }
  if (listen(s, 10) == -1)
    {
      close(s);
      return (-1);
    }
  return (s);
}
