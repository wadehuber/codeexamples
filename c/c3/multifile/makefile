all: multifile.c mystuff.o
	gcc --std=c11 -Wall -pedantic multifile.c mystuff.o

mystuff.o: mystuff.c
	gcc --std=c11 -Wall -pedantic -c mystuff.c

clean:
	rm -rf *.o *~ *.exe *.out
