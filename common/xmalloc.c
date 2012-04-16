/*
** xmalloc.c for xmalloc.c in /home/emax/Development/my_ftp/server
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Thu Apr  5 16:08:46 2012 maxime demouchy
** Last update Thu Apr  5 16:10:02 2012 maxime demouchy
*/

#include	<stdio.h>
#include	<stdlib.h>

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      printf("Error Malloc\n");
      exit(0);
    }
  return (ptr);
}
