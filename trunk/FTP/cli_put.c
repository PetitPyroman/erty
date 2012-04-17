/*
** cli_put.c for cli_put in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 15:28:44 2012 jules1 dourlens
** Last update Wed Apr  4 16:35:17 2012 jules1 dourlens
*/

#include		"header.h"

inline static void	put_trash(int fd, int *cpy, unsigned int w)
{
  if (w + 20 > filesize(fd))
    *cpy = filesize(fd) - w;
  else
    *cpy = 20;
}

inline static void	*put_very_trash(t_request *r, char *tmp, int fd)
{
  void			*file;

  file = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
  r->type = R_PUT;
  strcpy(r->param, tmp);
  r->len = filesize(fd);
  return (file);
}

void		cli_put(t_context *c, t_request *r, unsigned int w, int fd)
{
  char		buff[20];
  int		cpy;
  void		*file;
  char		*tmp;

  tmp = strtok(NULL, " ");
  if (tmp && access(tmp, R_OK))
    perror("access");
  else if (tmp)
    {
      fd = xopen(tmp, O_RDONLY);
      file = put_very_trash(r, tmp, fd);
      xwrite(c->socket, r, sizeof(*r));
      while (w < filesize(fd))
        {
	  put_trash(fd, &cpy, w);
          strncpy(buff, file + w, cpy);
          my_crypt(buff, cpy);
          w += xwrite(c->socket, buff, cpy);
        }
      munmap(file, filesize(fd));
      close(fd);
    }
  else
    printf("Error: You must provide an arg to put\n");
}
