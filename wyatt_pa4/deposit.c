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

void deposit()
{
	FILE *account;
	bank_account acc[50];
	int j = 0, m;
	double d;
	int found = 0;

	printf("Enter a six digit account number\n");
        scanf("%d" , &m);

        int r = (m == 0 ? 1 : (int)(log10(m)+1)); //calculate the length of the integer
        if (r < 6 || r > 6)
        { printf("\nInvalid: Must be 6 digits\n\n"); return; }

        account = fopen("accounts.dat" , "rb+");
        if (!account)
  	      { printf("\n****FAILED****\n"); exit(1); }

	printf("Enter amount to deposit\n");
	scanf("%lf" , &d);
	rewind(account);

	for (j = 0; (fread(&acc , sizeof(bank_account) , 1 , account)) != NULL; j++)
        {
		fseek(account , sizeof(bank_account)*j , SEEK_SET);
	        if (acc[j].account_number == m)
		{
			acc[j].balance += d;
			fwrite(&acc[j] , sizeof(acc[j]) , 1 , account);
			printf("\nNew balance: %.2lf\n" , acc[j].balance);
			found = 1;
		}
	}

	if (!found)
		{ printf("\nAccount not found\n"); return; }

	fclose(account);
}
