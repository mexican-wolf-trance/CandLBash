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

void deleteAccount()
{
	FILE *tmp_dat, *account;
	bank_account acc[50];
	int j = 0, m;
	int found = 0;

        printf("Enter a six digit account number\n");
        scanf("%d" , &m);

	int r = (m == 0 ? 1 : (int)(log10(m)+1));
	if (r < 6 || r > 6)
		{ printf("\nInvalid: Must be 6 digits\n\n"); return; }

	account = fopen("accounts.dat" , "rb");
	if (!account)
		{ printf("\n****FAILED****\n"); exit(1);	}

	tmp_dat = fopen("tmp.dat" , "wb");
	if (!tmp_dat)
		{ printf("\n****FAILED****\n"); exit(1); }

	for (j = 0; (fread(&acc , (sizeof(bank_account)) , 1 , account)) != NULL; j++)
	{
		fseek(account , sizeof(bank_account)*(j+1) , SEEK_SET);

		if (acc[j].account_number == m)
		{
			printf("\nAccount removed\n");
			found = 1;
		}
		else
			fwrite(&acc[j] , sizeof(acc[j]) , 1 , tmp_dat);
	}
	if (!found)
		printf("\nAccount not found\n\n");

	fclose(tmp_dat);
	fclose(account);

	remove("accounts.dat");
	rename("tmp.dat" , "accounts.dat");
}
