all: encrypt decrypt

encrypt: easycrypt.c
	gcc --std=c11 -pedantic -Wall easycrypt.c -o encrypt

decrypt: easycrypt.c
	gcc --std=c11 -pedantic -Wall easycrypt.c -DDECRYPT -o decrypt

clean:
	rm -f *.o *.exe *.out encrypt decrypt *~
