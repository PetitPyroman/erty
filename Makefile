##
## my_objdump.h for my_script in /home/emax/Development/my_script
## 
## Made by maxime demouchy
## Login   <demouc_m@epitech.net>
## 
## Started on  Mon Feb 28 13:41:34 2012 maxime demouchy
##

cp:
	cp ./src_server/serveur .
	cp ./src_client/client .

all: server client cp

server:
	$(MAKE) -C src_server all

client:
	$(MAKE) -C src_client all

re:
	$(MAKE) -C src_server re
	$(MAKE) -C src_client re
	cp ./src_server/serveur .
	cp ./src_client/client .

clean:
	$(MAKE) -C src_server clean
	$(MAKE) -C src_client clean

fclean:
	$(MAKE) -C src_server fclean
	$(MAKE) -C src_client fclean
	rm -f client
	rm -f serveur

.PHONY: server client