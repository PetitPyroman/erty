/*
** do_server.c for do_server in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr  4 17:55:55 2012 jules1 dourlens
** Last update Wed Apr  4 17:56:17 2012 jules1 dourlens
*/

#include	"header.h"

void		do_server(t_context *c)
{
  t_request	r;

  if (1 == read_handshake(c))
    {
      while (c->run)
        {
          if (sizeof(t_request) == serv_xread(c, c->socket,
                                              &r, sizeof(t_request)))
            {
              treat_request(c, &r);
            }
        }
    }
}
