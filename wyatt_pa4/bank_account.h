#ifndef _BANK_ACCOUNTH_
#define _BANK_ACCOUNTH_

#define N 100

typedef struct
{
        char first_name[N];
        char last_name[N];
        char middle_name[N];
        int account_number;
        double balance;
} bank_account;

#endif
