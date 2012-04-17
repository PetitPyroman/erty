/*
** treat_request.c for treat request in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Wed Apr  4 17:55:00 2012 jules1 dourlens
** Last update Wed Apr  4 17:55:27 2012 jules1 dourlens
*/

#include	"header.h"

void		treat_request(t_context *c, t_request *r)
{
  if (R_EXIT == r->type)
    serv_exit(c);
  else if (R_LS == r->type)
    ls(c);
  else if (R_LSI == r->type)
    lsi(c);
  else if (R_PWD == r->type)
    serv_pwd(c);
  else if (R_GET == r->type)
    serv_get(c, r, 0, 0);
  else if (R_CD == r->type)
    serv_cd(c, r);
  else if (R_PUT == r->type)
    serv_put(c, r);
  else if (R_RM == r->type)
    serv_rm(c, r);
}
