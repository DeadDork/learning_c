CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

ENTAB = entab
$(ENTAB) : $(ENTAB).o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(ENTAB).o : $(ENTAB).c

DETAB = detab
$(DETAB) : $(DETAB).o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
$(DETAB).o : $(DETAB).c

.PHONY : clean
clean :
	rm *.o $(ENTAB) $(DETAB)
