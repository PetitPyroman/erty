#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include	<stdio.h>
#include	<string.h>
#include <unistd.h>

#define FD_FREE		0
#define FD_CLIENT	1
#define FD_SERVER	2

#define MAX_FD		1024

typedef void	(*fct)();

typedef struct	s_env
{
  char	fd_type[MAX_FD];
  fct	fct_read[MAX_FD];
  fct	fct_write[MAX_FD];
  int	port;
}		t_env;
