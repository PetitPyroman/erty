/*
** client.h for client.h in /home/emax/Development/my_ftp/client
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 16:12:39 2012 maxime demouchy
** Last update Wed Apr 18 15:37:27 2012 jules1 dourlens
*/

#ifndef			__CLIENT__
#define			__CLIENT__

#include		<arpa/inet.h>
#include		<sys/select.h>

typedef struct		s_context
{
  int			socket;
  struct sockaddr_in	server;
  int			run;
}			t_context;

#endif
