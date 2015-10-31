CC=gcc

rumil: rumil.c bufferops.c
	$(CC) -o rumil -lncurses rumil.c bufferops.c