/*
** header.h for header.h in /home/emax/Development/my_ftp/includes
** 
** Made by maxime demouchy
** Login   <demouc_m@epitech.net>
** 
** Started on  Mon Apr  2 14:16:50 2012 maxime demouchy
** Last update Wed Apr 18 18:09:32 2012 maxime demouchy
*/

#ifndef		__HEADER__
#define		__HEADER__

#include	<time.h>

#define	LEN_NAME	32
#define	LEN_DATA	512

#define	PORC		4242

typedef enum
  {
    REGISTER,
    JOIN_CHAN,
    SEND_MESSAGE,
    QUIT_CHAN,
    LIST_CHAN,
    LIST_USERS,
    SEND_FILE,
    GET_FILE,
    ANSWER_OK,
    ANSWER_NO
  }t_type;

typedef struct	s_packet
{
  t_type	type;
  unsigned int	id;
  time_t	time;
  char		data[LEN_DATA];
  char		to[LEN_NAME];
}		t_packet;

#endif
