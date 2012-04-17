/*
** user_handler.c for user_handler in /home/dourle_a/Documents/myFTP
** 
** Made by jules1 dourlens
** Login   <dourle_a@epitech.net>
** 
** Started on  Sun Mar 25 23:25:22 2012 jules1 dourlens
** Last update Wed Apr  4 17:51:26 2012 jules1 dourlens
*/

#include	<stdio.h>
#include	"header.h"

static t_user	*create_user(char line[SIZE_LOGIN + SIZE_PASS + 2])
{
  t_user	*res;
  char		*t;

  res = malloc(sizeof(t_user));
  if (res != NULL)
    {
      t = strtok(line, ":");
      if (t && SIZE_LOGIN > strlen(t))
	strcpy((res->login), t);
      else
	return (NULL);
      t = strtok(NULL, ":");
      if (t && SIZE_PASS > strlen(t))
	strcpy((res->pass), t);
      else
	return (NULL);
      t = strtok(NULL, ":");
      if (t && t[0])
	res->rights = t[0];
      else
	return (NULL);
    }
  res->next = NULL;
  return (res);
}

static void	gay(t_context *c, t_user *tmp)
{
  tmp->next = c->users->next;
  c->users->next = tmp;
}

int		load_users(t_context *c)
{
  FILE		*file;
  char		line[SIZE_LOGIN + SIZE_PASS + 2];
  t_user	*tmp;

  c->users = NULL;
  file = fopen ("passwords", "r");
  if ( file != NULL )
    {
      while (fgets(line, sizeof(line), file) != NULL )
	{
	  tmp = create_user(line);
	  if (!tmp)
	    {
	      printf("Users error line: %s", line);
	      return (0);
	    }
	  if (c->users)
	    gay(c, tmp);
	  else
	    c->users = tmp;
	}
      fclose (file);
      return (1);
    }
  return (0);
}

int		login_user(t_context *c, t_handshake *h)
{
  t_user	*tmp;

  tmp = c->users;
  while (tmp)
    {
      if (0 == strcmp(h->login, tmp->login) && 0 == strcmp(h->pass, tmp->pass))
	{
	  printf("%i: logged in with login: %s\n", c->id, h->login);
	  goto_dirlogin(c, h->login);
	  c->rights = tmp->rights;
	  return (1);
	}
      tmp = tmp->next;
    }
  printf("%s: bad authentification detected!\n", h->login);
  return (0);
}
