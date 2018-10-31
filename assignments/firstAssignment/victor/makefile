CC=gcc
CFLAGS = -std=c99 -g -Wall
DEPS = typing_word_game.h
OBJ = typing_word_game.c

%.o: %c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@

typing_word_game: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm *.o
	clear
	clear
