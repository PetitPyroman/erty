/*
** file_utils.c for file_utils in /home/dourle_a/Documents/myIrc/tmp/erty/src_client
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Fri Apr 20 10:52:21 2012 jules1 dourlens
** Last update Sat Apr 21 14:20:44 2012 jules1 dourlens
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<errno.h>
#include	"header.h"
#include	"client.h"

void		id_ok_type(t_context *c, t_packet *packet, char *tmp, char *input)
{
  if (c && -2 == (int) packet->type)
    {
      packet->type = SEND_MESSAGE;
      strncpy(packet->data, input, LEN_DATA - 1);
    }
  else if (MSG_T == packet->type || JOIN_CHAN == packet->type
	   || SEND_MESSAGE == packet->type || LIST_CHAN == packet->type
	   ||  LIST_USERS == packet->type ||  QUIT_CHAN == packet->type
           || REGISTER == packet->type)
    {
      if (MSG_T == packet->type)
        {
          tmp = strtok(NULL, DELIM);
          strncpy(packet->to, tmp, LEN_NAME -1);
          packet->type = SEND_MESSAGE;
        }
      tmp = strtok(NULL, "\n");
      if (NULL != tmp)
        strncpy(packet->data, tmp, LEN_DATA - 1);
    }
}

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
  fclose(f);
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
  fclose(f);
  return (1);
}
