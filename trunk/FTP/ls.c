/*
** ls.c for ls in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
**
** Started on  Mon Mar 26 16:31:47 2012 jules1 dourlens
** Last update Thu Apr  5 15:50:04 2012 jules1 dourlens
*/

#include	"header.h"

void		ls(t_context *c)
{
  void		*file;
  int		fd;
  t_answer	a;
  unsigned int	w;

  w = 0;
  printf("%i: doing a ls\n", c->id);
  system("ls > /tmp/ftp_tmp");
  fd = xopen("/tmp/ftp_tmp", O_RDONLY);
  file = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
  a.len = filesize(fd);
  xwrite(c->socket, &a, sizeof(a));
  while (w < filesize(fd))
    {
      if (w + 20 > filesize(fd))
        w += xwrite(c->socket, file + w, filesize(fd) - w);
      else
        w += xwrite(c->socket, file + w, 20);
    }
  munmap(file, filesize(fd));
  close(fd);
}

void		lsi(t_context *c)
{
  void		*file;
  int		fd;
  t_answer	a;
  unsigned int	w;

  w = 0;
  printf("%i: doing a lsi\n", c->id);
  system("ls -la > /tmp/ftp_tmp");
  fd = xopen("/tmp/ftp_tmp", O_RDONLY);
  file = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
  a.len = filesize(fd);
  xwrite(c->socket, &a, sizeof(a));
  while (w < filesize(fd))
    {
      if (w + 20 > filesize(fd))
        w += xwrite(c->socket, file + w, filesize(fd) - w);
      else
        w += xwrite(c->socket, file + w, 20);
    }
  munmap(file, filesize(fd));
  close(fd);
}
