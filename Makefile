CC = gcc
CSF = -O2 -ansi -Wall -std=c99
CEF = -lncurses -lmenu

tetris: main.o start.o tetris.o
	$(CC) $(CSF) main.o start.o tetris.o -o tetris $(CEF) 

main.o: main.c start.h
	gcc $(CSF) -c main.c $(CEF)

start.o: start.c start.h
	gcc $(CSF) -c start.c $(CEF)

tetris.o: tetris.c tetris.h
	gcc $(CSF) -c tetris.c $(CEF)

clean:
	rm -f *.o
