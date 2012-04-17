/*
** cli_xread.c for xread in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:08:16 2012 jules1 dourlens
** Last update Thu Mar 29 20:27:49 2012 jules1 dourlens
*/

#include	"header.h"

ssize_t		cli_xread(int fd, void *b, size_t count)
{
  ssize_t	ret;

  ret = read(fd, b, count);
  if (-1 == ret)
    {
      perror("read");
      exit(1);
    }
  if (0 == ret)
    {
      printf("Error: Disconnected (Server side interrupted?)\n");
      close(fd);
      exit(0);
    }
  return (ret);
}
