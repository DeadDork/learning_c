CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

BIN_h = 1-13_h
OBJ_h = $(BIN_h).o

$(BIN_h) : $(OBJ_h)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_h).o : $(BIN_h).c

BIN_v = 1-13_v
OBJ_v = $(BIN_v).o

$(BIN_v) : $(OBJ_v)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_v).o : $(BIN_v).c

.PHONY : clean
clean :
	rm *.o *-[1-9][0-9]_[hv]
