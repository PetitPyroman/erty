/*
** cli_xread.c for xread in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:08:16 2012 jules1 dourlens
** Last update Thu Mar 29 20:29:12 2012 jules1 dourlens
*/

#include	"header.h"

ssize_t		serv_xread(t_context *c, int fd, void *b, size_t count)
{
  ssize_t	ret;

  ret = read(fd, b, count);
  if (-1 == ret)
    {
      perror("read");
      close(fd);
      exit(1);
    }
  if (0 == ret)
    {
      printf("%i: Disconnected (Client side interrupted?)\n", c->id);
      exit(0);
    }
  return (ret);
}
