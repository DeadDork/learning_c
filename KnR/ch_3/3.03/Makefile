CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

BIN = 3-3
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o *[0-9]
