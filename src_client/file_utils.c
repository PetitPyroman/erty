/*
** file_utils.c for file_utils in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr 20 10:52:21 2012 jules1 dourlens
** Last update Fri Apr 20 11:28:02 2012 jules1 dourlens
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	"header.h"
#include	"client.h"

int		send_a_file(t_packet *p, t_context *c, char *file)
{
  FILE		*f;

  (void) c;
  f = fopen(file, "r");
  if (!f)
    {
      perror("fopen");
      return (0);
    }
  fread(&(p->data), LEN_DATA - 1, sizeof(char), f);
  return (1);
}

int		write_a_file(t_packet *p, t_context *c, char *file)
{
  FILE		*f;

  (void) c;
  f = fopen(file, "w");
  if (!f)
    {
      perror("fopen");
      return (0);
    }
  fwrite(&(p->data), strlen(p->data), sizeof(char), f);
  return (1);
}
