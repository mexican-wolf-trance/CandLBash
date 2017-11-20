CC = gcc
CFLAGS = -g
TARGET = math
OBJS = main.o square.o cube.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
square.o: square.c
	$(CC) $(CFLAGS) -c square.c
cube.o: cube.c
	$(CC) $(CFLAGS) -c cube.c
clean:
	/bin/rm -f *.o $(TARGET)
