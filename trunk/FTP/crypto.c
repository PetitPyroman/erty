/*
** crypto.c for crypto in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 17:27:32 2012 jules1 dourlens
** Last update Mon Apr  2 12:22:43 2012 jules1 dourlens
*/

#include	"header.h"

void		my_crypt(char *s, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      s[i] = s[i] + 1;
      i++;
    }
}

void		my_uncrypt(char *s, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      s[i] = s[i] - 1;
      i++;
    }
}
