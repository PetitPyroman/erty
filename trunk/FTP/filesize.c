/*
** filesize.c for filesize in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 12:38:35 2012 jules1 dourlens
** Last update Mon Mar 26 12:40:10 2012 jules1 dourlens
*/

#include		"header.h"

inline unsigned int	filesize(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}
