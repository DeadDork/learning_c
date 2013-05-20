CC = gcc
CFLAGS = -Wall -Wextra -g # For debugging
LDFLAGS =

OBJ = main.o tempcon.o sstring.o rematch.o

BIN = tconv
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o tconv_[12]
