CC = gcc
CFLAGS = -Wall -Wextra #-g
LDFLAGS =

BIN = 3-2
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

BIN = newliner
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o *[0-9] newliner
