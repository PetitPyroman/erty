/*
** buffer_kill.c for buffer_kill in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Mon Mar 26 17:32:04 2012 jules1 dourlens
** Last update Mon Mar 26 17:33:34 2012 jules1 dourlens
*/

#include	"header.h"

char		*buffer_kill(char buffer[SIZE_LINE])
{
  if (strlen(buffer) > 1)
    buffer[strlen(buffer) - 1] = '\0';
  return (strtok(buffer, " "));
}
