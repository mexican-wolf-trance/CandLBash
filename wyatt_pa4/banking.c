/*Charles Wyatt
 cs 2750
 11/05/17 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#include "deposit.h"
#include "withdraw.h"
#include "addAccount.h"
#include "deleteAccount.h"
#include "balanceInquiry.h"
#include "viewAccounts.h"

#define N 100

int main()
{
	char x;
	while(1)
	{
		printf("0. Exit\n1. Deposit\n2. Withdraw\n3. Add Account\n4. Remove Account\n5. Balance Inquiry\n6. View Accounts\n");
		scanf(" %c" , &x);

		if (x == '0')
			{ printf("Thank you for BANKING on us!\n"); break; }
		else if (x == '1') //Deposit
			deposit();
		else if (x == '2') //Withdraw
			withdraw();
		else if (x == '3') //Add account
			addAccount();
		else if (x == '4') //Delete account
			deleteAccount();
		else if (x == '5') //Balance inquiry
			balanceInquiry();
		else if (x == '6') //View accounts
			viewAccounts();
		else { printf("Invalid selection\n"); continue; }
	}
	return 0;
}
