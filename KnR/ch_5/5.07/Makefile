CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

BIN_1 = original_string_sort
OBJ_1 = $(BIN_1).o
$(BIN_1) : $(OBJ_1)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ_1).o : $(OBJ_1).c

BIN_2 = new_string_sort
OBJ_2 = $(BIN_2).o
$(BIN_2) : $(OBJ_2)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ_2).o : $(OBJ_2).c

.PHONY : clean
clean :
	rm *.o $(BIN_1) $(BIN_2)
