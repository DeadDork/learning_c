CC = gcc
CFLAGS = -Wall -Wextra -g
CCFLAGS = 
LDFLAGS =

BIN = fopen_1
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ) : $(BIN).c

.PHONY : clean
clean :
	rm *.o $(BIN)
