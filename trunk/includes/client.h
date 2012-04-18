/*
** client.h for client.h in /home/emax/Development/my_ftp/client
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 16:12:39 2012 maxime demouchy
** Last update Wed Apr 18 21:39:11 2012 jules1 dourlens
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

#define DELIM		" "

typedef struct		s_gui_box
{
  int			x;
  int			y;
  WINDOW		*win;
  int			w;
  int			h;
}			t_gui_box;

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
  t_gui_box		records;
}			t_context;

#endif
