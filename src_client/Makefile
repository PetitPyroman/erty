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

LDFLAGS += -lncurses

NAME =			client

SOURCES =		xfuncs.c \
			file_utils.c \
			get_funcs.c \
			main.c \

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
