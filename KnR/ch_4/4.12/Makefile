CC = gcc
CFLAGS = -Wall -Wextra #-g
LDFLAGS =

BIN = itoa_demo
OBJ = 4-12.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
