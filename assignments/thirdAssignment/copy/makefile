CC=gcc
CFLAGS = -std=c99 -g -Wall -lm # -lm to link the math.h library
DEPS = main.h#this is where the header files go. 
OBJ1 = main.c 
PROGS=  float_To_Hex_Converter

all: $(PROGS)

%.o: %c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@

float_To_Hex_Converter: $(OBJ1)
		$(CC) $^ $(CFLAGS) -o $@

clean: 
	rm *.o
	clear
	clear
