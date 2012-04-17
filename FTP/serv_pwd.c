/*
** serv_pwd.c for serv_pwd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:19:10 2012 jules1 dourlens
** Last update Wed Apr  4 17:51:47 2012 jules1 dourlens
*/

#include	"header.h"

void		serv_pwd(t_context *c)
{
  void          *file;
  int           fd;
  t_answer      a;
  unsigned int  w;

  w = 0;
  printf("%i: doing a pwd\n", c->id);
  system("pwd > /tmp/ftp_tmp");
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

