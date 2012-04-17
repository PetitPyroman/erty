/*
** cli_cmd.c for cli cmd in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Tue Mar 27 14:56:12 2012 jules1 dourlens
** Last update Wed Apr  4 15:32:08 2012 jules1 dourlens
*/

#include	"header.h"

void		cli_cmd(t_context *c, char *cmd)
{
  (void) c;
  if (cmd)
    system(cmd);
  else
    printf("Error : You must provide a cmd\n");
}
