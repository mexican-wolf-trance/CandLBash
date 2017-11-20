CC = gcc
CFLAGS = -Wall -g -std=c99 -lm
TARGET = wordC
OBJ1 = wordStats.o cl_wordStat.o man_wordStats.o
TARGET2 = bank
OBJ2 = banking.o deposit.o withdraw.o addAccount.o deleteAccount.o balanceInquiry.o viewAccounts.o
all: $(TARGET) $(TARGET2)
$(TARGET): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ1)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o  $(TARGET2) $(OBJ2)
banking.o: banking.c bank_account.h deposit.h withdraw.h addAccount.h deleteAccount.h balanceInquiry.h viewAccounts.h
	$(CC) $(CFLAGS) -c banking.c
deposit.o: deposit.c deposit.h bank_account.h
	$(CC) $(CFLAGS) -c deposit.c
withdraw.o: withdraw.c withdraw.h bank_account.h
	$(CC) $(CFLAGS) -c withdraw.c
addAccount.o: addAccount.c addAccount.h bank_account.h
	$(CC) $(CFLAGS) -c addAccount.c
deleteAccount.o: deleteAccount.c deleteAccount.h bank_account.h
	$(CC) $(CFLAGS) -c deleteAccount.c
balanceInquiry.o: balanceInquiry.c balanceInquiry.h bank_account.h
	$(CC) $(CFLAGS) -c balanceInquiry.c
viewAccounts.o: viewAccounts.c viewAccounts.h bank_account.h
	$(CC) $(CFLAGS) -c viewAccounts.c
wordStats.o: cl_wordStat.h man_wordStats.h wordStats.c
	$(CC) $(CFLAGS) -c wordStats.c
cl_wordStat.o: cl_wordStat.h cl_wordStat.c
	$(CC) $(CFLAGS) -c cl_wordStat.c
man_wordStats.o: man_wordStats.h man_wordStats.c
	$(CC) $(CFLAGS)	-c man_wordStats.c

clean:
	/bin/rm -f *.o  $(TARGET) $(TARGET2)

