#/bin/sh
all: Compress.exe

Compress.exe: Compress.o
	 gcc -o Compress Compress.o -lm -w

Compress.o: Compress.c
	 gcc -c Compress.c -lm -w
     
clean:
	 rm Compress.o Compress

run:
	./Compress
