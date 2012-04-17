/*
** main.c for main in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Sun Mar 25 16:35:57 2012 jules1 dourlens
** Last update Sun Apr  8 10:59:06 2012 jules1 dourlens
*/

#include "header.h"

void		try_connect(t_context *c, char **argv)
{
  t_handshake	h;

  c->id = 0;
  c->run = 1;
  c->listening = xsocket(AF_INET, SOCK_STREAM, 0);
  memset(&(c->server), 0, sizeof(c->server));
  c->server.sin_family = AF_INET;
  xinet_aton(argv[1], &(c->server.sin_addr));
  c->server.sin_port = htons(atoi(argv[2]));
  xconnect(c->listening, (struct sockaddr *) &(c->server), sizeof(c->server));
  c->socket = c->listening;
  strcpy(h.login, argv[3]);
  strcpy(h.pass, argv[4]);
  xwrite(c->socket, &h, sizeof(h));
  cli_check_login(c);
  send_request(c);
  close(c->socket);
}

int		main(int argc, char **argv)
{
  t_context	c;

  if (argc == 2)
    wait_connect(&c, atoi(argv[1]));
  else if (argc == 5)
    try_connect(&c, argv);
  else
    {
      printf("server : [PORT]\n");
      printf("client : [IP] [PORT] [USER] [PASSWORD]\n");
    }
  return (1);
}
