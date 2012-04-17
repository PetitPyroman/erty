/*
** server.c for server in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Thu Apr  5 16:22:00 2012 jules1 dourlens
** Last update Thu Apr  5 17:30:13 2012 jules1 dourlens
*/

#include	"header.h"

static void	init_server(t_context *c, int port)
{
  load_users(c);
  c->id = 0;
  c->run = 1;
  getcwd(c->path, PATH_LEN);
  c->listening = socket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  c->server.sin_addr.s_addr = htonl(INADDR_ANY);
  c->server.sin_port = htons(port);
  xbind(c->listening, (struct sockaddr *) &(c->server), sizeof(c->server));
  xlisten(c->listening, LISTENQ);
}

void		wait_connect(t_context *c, int port)
{
  pid_t		pid;

  printf("Launching FTP server\n");
  init_server(c, port);
  while (c->run)
    {
      c->socket = accept(c->listening, NULL, NULL);
      pid = xfork();
      if (0 == pid)
        {
          do_server(c);
          close(c->socket);
          c->run = 0;
        }
      c->id++;
      close(c->socket);
    }
}
