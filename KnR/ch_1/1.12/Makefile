CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

BIN = 1-12
OBJ = $(BIN).o


$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

.PHONY : clean
clean :
	rm *.o *[-][1-9][0-9]
