objects = main.o server_functions.o

headers = server.h structures.h ../medit_defaults.h

tp_server: $(objects)
	gcc -o tp_server $(objects) -I . -pthread

main.o: main.c $(headers)
server_functions.o: server_functions.c $(headers)

clean:
	rm *.o
