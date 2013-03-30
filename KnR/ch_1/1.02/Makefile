CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

BIN_1 = 1-2
OBJ_1 = $(BIN_1).o

BIN_2 = alert_1
OBJ_2 = $(BIN_2).o

$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_1).o : $(BIN_1).c

$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(BIN_2).o : $(BIN_2).c

.PHONY : clean
clean :
	rm *.o *[_-][1-9]
