/*
** client.h for client.h in /home/emax/Development/my_ftp/client
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Sun Apr  8 16:12:39 2012 maxime demouchy
** Last update Fri Apr 20 15:03:07 2012 jules1 dourlens
*/

#ifndef			__CLIENT__
#define			__CLIENT__

#include		<arpa/inet.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		<ncurses.h>
#include		"header.h"

/*
** Parser things
*/
#define DELIM		" "

#define JOIN		"/join"
#define PART		"/part"
#define NICK		"/nick"
#define CHAN		"/list"
#define USERS		"/users"
#define MSG		"/msg"
#define SEND		"/send_file"
#define ACCEPT		"/accept_file"

/*
** INNER Client types!
*/
#define MSG_T		145
#define ACCEPT_T	69
#define SEND_T		84

typedef struct		s_context
{
  char			accept[LEN_NAME];
  int			socket;
  struct sockaddr_in	server;
  int			run;
  fd_set		read;
}			t_context;

#endif
