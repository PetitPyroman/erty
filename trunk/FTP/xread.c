/*
** xread.c for x_read in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Sun Mar 25 22:37:32 2012 jules1 dourlens
** Last update Mon Mar 26 16:08:09 2012 jules1 dourlens
*/

#include	"header.h"

ssize_t		xread(int fd, void *b, size_t count)
{
  ssize_t	ret;

  ret = read(fd, b, count);
  if (-1 == ret)
    {
      perror("read");
      exit(1);
    }
  return (ret);
}
