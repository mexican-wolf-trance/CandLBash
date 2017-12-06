CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET2 = phone
OBJ2 = phone.o phone_fmt.o
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2)
phone.o: phone.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone.c
phone_fmt.o: phone_fmt.c phone_fmt.h
	$(CC) $(CFLAGS) -c phone_fmt.c

clean:
	/bin/rm -f *.o  $(TARGET2)
