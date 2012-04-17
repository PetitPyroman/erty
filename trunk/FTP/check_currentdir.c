/*
** check_currentdir.c for check_current_dir in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 11:00:40 2012 jules1 dourlens
** Last update Tue Mar 27 16:39:52 2012 jules1 dourlens
*/

#include	"header.h"

int		check_currentdir(t_context *c, char *old)
{
  char		buff[255];

  getcwd(buff, 255);
  if (!strstr(buff, c->path) || !strlen(strstr(buff, c->path)))
    {
      if (c->rights == U_ADMIN)
	{
	  printf("Warning: %i is away from %s\n", c->id, c->path);
	  free(old);
	  return (1);
	}
      chdir(old);
      printf("Warning: tried to get away from %s\n", c->path);
      free(old);
      return (-1);
    }
  free(old);
  return (1);
}
