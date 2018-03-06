CC=g++
CFLAGS=-I.
DEPS = SortNumbers.h
OBJ = SortNumbers.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SortNumbers: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
