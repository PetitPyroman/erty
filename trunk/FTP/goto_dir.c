/*
** goto_dir.c for gotodir in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 10:52:44 2012 jules1 dourlens
** Last update Wed Apr  4 15:30:43 2012 jules1 dourlens
*/

#include	"header.h"

void		goto_dir(t_context *c, char *login)
{
  char		path[255];

  (void) c;
  strcpy(path, "./www/");
  strcat(path, login);
  if (chdir(path))
    {
      perror("chdir");
      printf("You have to have rights on ./www/[LOGIN]!\n");
      exit (1);
    }
}

void		goto_dirlogin(t_context *c, char *login)
{
  char		path[255];

  strcpy(path, "./www/");
  strcat(path, login);
  strcpy(c->path, path);
  if (chdir(path))
    {
      perror("chdir");
      printf("You have to have rights on ./www/[LOGIN]!\n");
      exit (1);
    }
}
