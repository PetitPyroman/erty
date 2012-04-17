/*
** dispatch.c for dispatch in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Sun Apr  8 10:58:22 2012 jules1 dourlens
** Last update Sun Apr  8 10:59:29 2012 jules1 dourlens
*/

#include	"header.h"

static void	send_local(t_context *c, char *tmp, t_request *r)
{
  if (0 == strcmp(tmp, "lpwd"))
    cli_lpwd(c);
  else if (0 == strcmp(tmp, "lls"))
    cli_lls(c);
  else if (0 == strcmp(tmp, "pwd"))
    cli_pwd(c, r);
  else if (0 == strcmp(tmp, "cd"))
    cli_cd(c, r);
  else if (0 == strcmp(tmp, "lcd"))
    cli_lcd(c);
  else if (0 == strcmp(tmp, "!cmd"))
    cli_cmd(c, strtok(NULL, "\n"));
  else
    printf("Uknown command for your user rights!\n");
}

void		send_request(t_context *c)
{
  t_request	r;
  char		buffer[SIZE_LINE];
  char		*tmp;

  while (c->run && printf("FTP $>") && fgets(buffer, sizeof(buffer), stdin))
    {
      tmp = buffer_kill(buffer);
      if (0 == strcmp(tmp, "exit"))
        cli_exit(c, &r);
      else if (0 == strcmp(tmp, "ls"))
        cli_ls(c, &r);
      else if (0 == strcmp(tmp, "lsi"))
        cli_lsi(c, &r);
      else if (0 == strcmp(tmp, "get"))
        cli_get(c, &r);
      else if (0 == strcmp(tmp, "put") && c->rights < U_R)
        cli_put(c, &r, 0, 0);
      else if (0 == strcmp(tmp, "rm") && c->rights < U_R)
        cli_rm(c, &r);
      else
        send_local(c, tmp, &r);
    }
}
