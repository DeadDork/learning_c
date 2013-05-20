CC = gcc
CFLAGS = -Wall -Wextra -g # For debugging
LDFLAGS =

OBJ = main.o tempcon.o sstring.o rematch.o

tconv_1 : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

main.o : main.c tempcon.h sstring.h
tempcon.o : tempcon.c tempcon.h sstring.h rematch.h
sstring.o : sstring.c sstring.h rematch.h
rematch.o : rematch.c rematch.h

BIN_2 = tconv_2
OBJ_2 = $(BIN_2).o
$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 
$(BIN_2).o : $(BIN_2).c

.PHONY : clean
clean :
	rm *.o tconv_[12]
