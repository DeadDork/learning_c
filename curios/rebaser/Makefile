CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

BIN = rebaser
OBJ = $(BIN).o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o rebaser
