CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

BIN_1 = regex-sub_1
OBJ_1 = $(BIN_1).o sstring.o rematch.o

$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_1).o : $(BIN_1).c
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

.PHONY : clean
clean :
	rm *.o *[_-][1-9]
