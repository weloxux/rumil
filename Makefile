CC=gcc

rumil: rumil.c fileops.c
	$(CC) -o rumil -lncurses rumil.c fileops.c