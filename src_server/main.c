/*
** main.c for main.c in /home/emax/Development/my_ftp
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:13:47 2012 maxime demouchy
** Last update Mon Apr 16 16:47:25 2012 maxime demouchy
*/

#include	<sys/socket.h>
#include	<sys/types.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"header.h"
#include	"server.h"
#include	"common.h"

int	launch_server(int s_server)
{
  int			client_len;
  int			s_client;
  struct sockaddr_in	sin_client;

  client_len = sizeof(sin_client);
  while (1)
    {
      if ((s_client = accept(s_server,
			     (struct sockaddr *)&sin_client,
			     (socklen_t *)&client_len)) == -1)
	{
	  close(s_server);
	  return (-1);
	}
      //accept SUCCESS
    }
  return (1);
}

int	main(int argc, char **argv)
{
  int	s_server;

  (void)argc;
  (void)argv;
  if ((s_server = init_server(45455)) == -1)
    printf("Erreur initialisation server !\n");
  else
    {
      
    }
  return (0);
}
