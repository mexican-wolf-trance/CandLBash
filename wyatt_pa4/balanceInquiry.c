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

void balanceInquiry()
{
	FILE *account;
	bank_account acc[50];
	unsigned int i;
	struct stat st;
	int j = 0, m;

	account = fopen("accounts.dat" , "rb+");
	stat("accounts.dat" , &st);
        i = st.st_size / sizeof(bank_account);

        if (!account)
              	{ printf("\n****FAILED****\n"); exit(1); }

	printf("Enter a six digit account number\n");
        scanf("%d" , &m);

        int r = (m == 0 ? 1 : (int)(log10(m)+1));
        if (r < 6 || r > 6)
  		{ printf("Invalid: Must be 6 digits\n\n"); return; }

        fread(&acc , sizeof(bank_account) , 1 , account);
        for (j = 0; j < i; j++)
	if (acc[j].account_number == m)
              	printf("*****************\nAccount %d\nName: %s %s %s\nBalance: %.2lf\nAccount Number: %d\n*****************\n" , (j+1) , acc[j].first_name, acc[j].middle_name, acc[j].last_name, acc[j].balance, acc[j].account_number);

	fclose(account);
}
