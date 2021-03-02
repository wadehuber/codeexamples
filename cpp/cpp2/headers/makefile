CC=g++
CPPFLAGS=--std=c++17 -Wall -pedantic

all: headers.cpp rectangle.o triangle.o circle.o square.o
	$(CC) $(CPPFLAGS) headers.cpp rectangle.o triangle.o circle.o square.o

rectangle.o: rectangle.cpp
	$(CC) $(CPPFLAGS) -c rectangle.cpp

triangle.o: triangle.cpp
	$(CC) $(CPPFLAGS) -c triangle.cpp

circle.o: circle.cpp
	$(CC) $(CPPFLAGS) -c circle.cpp

square.o: square.cpp
	$(CC) $(CPPFLAGS) -c square.cpp

clean:
	rm -f *.o *.exe *.out
