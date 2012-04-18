/*
** header.h for header.h in /home/emax/Development/my_ftp/includes
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:16:50 2012 maxime demouchy
** Last update Wed Apr 18 14:52:09 2012 maxime demouchy
*/

#ifndef		__HEADER__
#define		__HEADER__

#include	<time.h>

#define	LEN_NAME	32

typedef enum
  {
    REGISTER,
    SEND_MESSAGE,
    SEND_FILE,
    GET_FILE,
    QUIT_CHAN,
    LIST_CHAN
  }t_type;

typedef struct	s_packet
{
  t_type	type;
  char		data[512];
  char		to[LEN_NAME];
  char		to_chan[LEN_NAME];
  time_t	time;
}		t_packet;

#endif
