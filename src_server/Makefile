##
## phylo.h for my_script in /home/emax/Development/my_script
## 
## Made by maxime demouchy
## Login   <demouc_m@epitech.net>
## 
## Started on  Mon Feb 28 13:41:34 2012 maxime demouchy
##

CC = gcc

RM = rm -rf

CFLAGS += -W -Wall -Wextra  -g -I ../includes/

LDFLAGS +=

NAME =			serveur

SOURCES =		main.c				\
			../common/xbind.c		\
			xlisten.c			\
			users_utils.c			\
			channel_utils.c			\
			init_server.c			\
			utils_select.c			\
			receive_utils.c			\
			command_register.c		\
			command_join.c			\
			command_quit_chan.c		\
			command_list_chan.c		\
			command_list_users.c		\
			command_send_message.c		\
			command_send_file.c		\
			utils_connection.c		\

OBJECTS =  $(SOURCES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS) 
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:     clean fclean all

.c.o:
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) -c $< -g -W -Wall
