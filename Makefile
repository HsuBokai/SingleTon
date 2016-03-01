LDIR =./lib
IDIR =./include
CC=g++
CFLAGS= -g -Wall -I$(IDIR)

TARGET = main
OBJ = main.o rand.o logger.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f *.o *~ $(INCDIR)/*~ $(TARGET)
