main: backend.o
	gcc -pthread backend.o -o tp3 main.c -Wall -Wextra -Werror -std=c99 -pedantic

backend.o: backend.c
	gcc -c -pthread backend.c

clean:
	rm -rf beckend.o
	rm -rf *.o
