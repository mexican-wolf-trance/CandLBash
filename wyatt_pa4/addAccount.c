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

void addAccount()
{
	FILE *account;
	bank_account acc[50];
	int j = 0;
	unsigned long i;
	struct stat st;
       	int r, try;

	account = fopen("accounts.dat" , "ab+");
	stat("accounts.dat" , &st);
	i = st.st_size / sizeof(bank_account);
	if (!account)
	       	{ printf("\n****FAILED****\n"); exit(1); }
	else
	{
       	        printf("Enter your first name\n");
       	        scanf("%s" , &(acc[i].first_name));
       	        printf("Enter your last name\n");
       	        scanf("%s" , &(acc[i].last_name));
       	        printf("Enter your middle name\n");
       	        scanf("%s" , &(acc[i].middle_name));
		printf("Enter a six digit account number\n");
       	        scanf("%d" , &(acc[i].account_number));
		r = (acc[i].account_number == 0 ? 1 : (int)(log10(acc[i].account_number)+1));
		try = 0;
		if (r < 6 || r > 6)
        	        { printf("Invalid: Must be 6 digits\n"); return; }

		else if (st.st_size >= sizeof(bank_account))
		{
			j = 0;
			fseek(account , 0 , SEEK_SET);
			fread(&acc , (sizeof(bank_account)) , 1 , account);
			while (j < i)
			{
				if(acc[i].account_number == acc[j].account_number)
				{
					printf("Invalid: Account number already exists\n\n");
					try = 1;
					break;
				}
				j++;
			}
		}
		if (try == 1)
			return;
		printf("Enter your starting balance\n");
               	scanf("%lf" , &(acc[i].balance));

		fseek(account , 0 , SEEK_END);
		fwrite(&acc[i] , (sizeof(acc[i])) , 1 , account);
		printf("\nAccount created\n\n");

		fclose(account);
	}
}
