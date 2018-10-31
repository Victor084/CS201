CC=gcc
CFLAGS = -m32 -std=c99 -g -Wall
DEPS = showbits.h setbits.h
OBJ1 = showBits.c 
OBJ2 = setBits.c
PROGS= setBits showBits

all: $(PROGS)

%.o: %c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@

showBits: $(OBJ1)
		$(CC) $(CFLAGS) -o $@ $^

setBits: $(OBJ2)
		$(CC) $(CFLAGS) -o $@ $^
clean: 
	rm *.o
	clear
	clear
