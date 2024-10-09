CC = g++
CFLAGS = -c -g
LDFLAGS =
OBJECTS = main.o

run: all 
	program
all: program

program : $(OBJECTS)
	$(CC) $(LDFLAGS) -o program $(OBJECTS)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o\

	