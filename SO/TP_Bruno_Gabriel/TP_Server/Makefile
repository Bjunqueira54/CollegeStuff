objects = main.o server_functions.o
CFLAGS	= -I . -g -ggdb
headers = server.h structures.h ../medit_defaults.h

tp_server: $(objects)
	gcc -o tp_server $(objects) $(CFLAGS) -pthread

main.o: main.c $(headers)
server_functions.o: server_functions.c $(headers)

clean:
	rm *.o
