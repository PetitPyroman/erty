/*
** xwrite.c for xwrite in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Sun Mar 25 22:39:29 2012 jules1 dourlens
** Last update Thu Mar 29 20:30:24 2012 jules1 dourlens
*/

#include	"header.h"

inline ssize_t	xwrite(int fd, const void *buf, size_t count)
{
  ssize_t	ret;

  ret = write(fd, buf, count);
  if (-1 == ret)
    {
      perror("write");
      exit(1);
    }
  return (ret);
}
