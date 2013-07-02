CC = gcc
CFLAGS = -Wall -Wextra #-g
CCFLAGS = #-fnested-functions
LDFLAGS =

BIN = static_1
OBJ = $(BIN).o static_func_1.o
$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN).o : $(BIN).c

static_func_1.o : static_func_1.c

.PHONY : clean
clean :
	rm *.o *[_-][1-9]
