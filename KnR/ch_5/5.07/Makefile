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

BIN_3 = test_original_string_sort
OBJ_3 = $(BIN_3).o
$(BIN_3) : $(OBJ_3)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ_3).o : $(OBJ_3).c

BIN_4 = test_new_string_sort
OBJ_4 = $(BIN_4).o
$(BIN_4) : $(OBJ_4)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(OBJ_4).o : $(OBJ_4).c

.PHONY : clean
clean :
	rm *.o $(BIN_1) $(BIN_2) $(BIN_3) $(BIN_4)
