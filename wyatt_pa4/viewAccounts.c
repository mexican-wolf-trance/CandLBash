#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#include "bank_account.h"

#define N 100

void viewAccounts()
{
	FILE *account;
	bank_account acc[50];
	int j = 0;
	unsigned long i;
	struct stat st;

	account = fopen("accounts.dat" , "rb+");
	stat("accounts.dat" , &st);
        i = st.st_size / sizeof(bank_account);

	if (!account)
              	{ printf("\n****FAILED****\n"); exit(1); }

	for (j = 0; j < i; j++)
	{
		bank_account temp[1];
		fread(&temp , sizeof(bank_account) , 1 , account);
		acc[j] = *temp;
		fseek(account , sizeof(bank_account)*(j+1) , SEEK_SET);
		printf("*****************\nAccount %d\nName: %s %s %s\nBalance: %.2lf\nAccount Number: %d\n*****************\n" , (j+1) , acc[j].first_name, acc[j].middle_name, acc[j].last_name, acc[j].balance, acc[j].account_number);
	}

	fclose(account);
}
