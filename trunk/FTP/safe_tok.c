/*
** safe_tok.c for src safe_tok in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr  4 15:51:02 2012 jules1 dourlens
** Last update Sun Apr  8 11:25:36 2012 jules1 dourlens
*/

#include	"header.h"

char		*safe_tok(void)
{
  char		*tmp;

  tmp = strtok(NULL, " ");
  if (!tmp)
    {
      printf("Missing arg to command!\n");
      return (NULL);
    }
  if (strcmp(tmp, "server") == 0 || strcmp(tmp, "client") == 0)
    {
      printf("You can't transfer binary file!!\n");
      return (NULL);
    }
  if (strstr(tmp, ";"))
    {
      printf("Bad Format ;\n");
      return (NULL);
    }
  return (tmp);
}
