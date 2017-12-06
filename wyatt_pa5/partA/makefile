CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET = deater
OBJ1 = main.o addInput.o substringInput.o
$(TARGET): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ1)
main.o: main.c addInput.h substringInput.h
	$(CC) $(CFLAGS) -c main.c
addInput.o: addInput.c addInput.h 
	$(CC) $(CFLAGS) -c addInput.c
substringInput.o: substringInput.c substringInput.h  
	$(CC) $(CFLAGS) -c substringInput.c

clean:
	/bin/rm -f *.o  $(TARGET)
