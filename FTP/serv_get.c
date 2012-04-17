/*
** serv_get.c for serv_get in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:44:50 2012 jules1 dourlens
** Last update Wed Apr  4 17:54:04 2012 jules1 dourlens
*/

#include		"header.h"

inline static void	serv_put_trash(int fd,
				       int *cpy, unsigned int w)
{
  if (w + 20 > filesize(fd))
    *cpy = filesize(fd) - w;
  else
    *cpy = 20;
}

static void		lol(t_answer *a, t_context *c)
{
  perror("access");
  a->len = -1;
  xwrite(c->socket, a, sizeof(*a));
}

void			serv_get(t_context *c,
				 t_request *r, int fd, unsigned int w)
{
  void			*file;
  t_answer		a;
  char			buff[20];
  int			cpy;

  printf("%i: doing a get on %s\n", c->id, r->param);
  if (access(r->param, R_OK))
    lol(&a, c);
  else
    {
      fd = xopen(r->param, O_RDONLY);
      file = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
      a.len = filesize(fd);
      xwrite(c->socket, &a, sizeof(a));
      while (w < filesize(fd))
	{
	  serv_put_trash(fd, &cpy, w);
	  strncpy(buff, file + w, cpy);
	  my_crypt(buff, cpy);
	  w += xwrite(c->socket, buff, cpy);
	}
      munmap(file, filesize(fd));
      close(fd);
    }
}
