/*
** client.h for client.h in /home/emax/Development/my_ftp/client
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 16:12:39 2012 maxime demouchy
** Last update Thu Apr 19 18:13:30 2012 jules1 dourlens
*/

#ifndef			__CLIENT__
#define			__CLIENT__

#include		<arpa/inet.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		<ncurses.h>

#define JOIN		"/join"
#define PART		"/part"
#define NICK		"/nick"
#define CHAN		"/list"
#define USERS		"/users"
#define MSG		"/msg"

#define MSG_T		145

#define DELIM		" "

typedef struct		s_event
{
  int			type;
  int			id;
  struct s_event	*next;
}			t_event;

typedef struct		s_context
{
  int			socket;
  struct sockaddr_in	server;
  int			run;
  fd_set		read;
  t_event		*events;
}			t_context;

#endif
