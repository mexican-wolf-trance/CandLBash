CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET = deater
OBJ1 = main.o addInput.o substringInput.o
TARGET2 = phone
OBJ2 = phone.o phone_fmt.o
all: $(TARGET) $(TARGET2)
$(TARGET): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)
main.o: main.c addInput.h substringInput.h
	$(CC) $(CFLAGS) -c main.c
addInput.o: addInput.c addInput.h 
	$(CC) $(CFLAGS) -c addInput.c
substringInput.o: substringInput.c substringInput.h  
	$(CC) $(CFLAGS) -c substringInput.c
phone.o: phone.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone.c
phone_fmt.o: phone_fmt.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone_fmt.c



clean:
	/bin/rm -f *.o  $(TARGET) $(TARGET2)
