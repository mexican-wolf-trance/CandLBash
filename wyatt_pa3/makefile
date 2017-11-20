CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET = math
OBJS = main.o avg.o sum.o min.o max.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: avg.h sum.h max.h min.h main.c 
	$(CC) $(CFLAGS) -c main.c
avg.o: sum.h avg.c
	$(CC) $(CFLAGS) -c avg.c
sum.o: sum.c
	$(CC) $(CFLAGS) -c sum.c
min.o: min.c
	$(CC) $(CFLAGS) -c min.c
max.o: max.c
	$(CC) $(CFLAGS) -c max.c

clean:
	/bin/rm -f *.o $(TARGET)
