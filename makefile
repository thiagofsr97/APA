CC=g++
CFLAGS=-I.
DEPS = SortNumbers.h Heap.h
OBJ = SortNumbers.o Heap.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SortNumbers: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
