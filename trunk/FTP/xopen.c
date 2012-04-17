/*
** xopen.c for xopen in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 16:49:00 2012 jules1 dourlens
** Last update Mon Mar 26 16:50:33 2012 jules1 dourlens
*/

#include	"header.h"

int		xopen(const char *pathname, int flags)
{
  int		ret;

  ret = open(pathname, flags);
  if (-1 == ret)
    {
      perror("open");
      exit(1);
    }
  return (ret);
}
