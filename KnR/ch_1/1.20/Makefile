CC = gcc
CFLAGS = -Wall -Wextra #-g
LDFLAGS =

BIN = 1-20
OBJ = $(BIN).o sstring.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c sstring.h

sstring.o : sstring.c sstring.h

.PHONY : clean
clean :
	rm *.o *[-][1-9][0-9]
