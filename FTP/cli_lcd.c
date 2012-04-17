/*
** cli_lcd.c for lsd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 10:38:21 2012 jules1 dourlens
** Last update Wed Apr  4 16:10:56 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_lcd(t_context *c)
{
  char		*tmp;

  (void) c;
  tmp = strtok(NULL, " ");
  if (tmp)
    {
      if (chdir(tmp))
	{
	  perror("chdir");
	}
    }
  else
    {
      printf("Error: Provide a directory to go to\n");
    }
}
