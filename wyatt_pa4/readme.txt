			*************************
			Readme file for banking.c
			*************************

Lines 5-12:
	Declare libraries
Lines 14-23:
	Define N and declare struct
Lines 25-32:
	Begin main function and declare variables
	struct stat st -> Used to find the size of "accounts.dat"
Line 33:
	Begin banking menu
Lines 35-36:
	Display menu and ask user for selection
Lines 37-41:
	If the user selects '0', break out of the while loop, thus ending the
	program.
Lines 42-86:
	If the user selects '1', make a deposit into an account
	44-45 - declare variables
	46-47 - Ask the user for their account number
	48 - determine the length of the account number (if m = 123456, r = 6)
	49-53 - if the account number is more or less than 6 digits long, 
		the user is taken back to the menu
	54 - open the file "accounts.dat" in read binary(+) mode
	55-56 - determine the size of "accounts.dat" in number of bytes,
		then divide that by the size of one struct bank_account in
		number of bytes to get the number of bank accounts stored
	57-61 - if the file fails to open, terminate the program
	62-63 - ask the user how much they would like to deposit
	64 - make sure we start at the top of the file
	65-77 - as long we haven't reached the end of the file, we search for
		the account that corresponds with the account number the user
		entered, then we copy the entire account back into the file
		while updating the balance by adding the deposit amount and
		set 'found' to 1. however, if the account number does not 
		correspond to any stored accounts, 'found' will equal 0.
	80-84 - if 'found' = 0, then it will report that the account was not 
		found and return to the menu
	85 - close the file stream
Lines 87-130:
	If the user selects '2', make a withdrawl from the account
	89-90 - declare variables
	91-92 - ask the user for their account number
	93 - determine the length of the account number (if m = 123456, r = 6)
	94-98 - if the account number is more or less than 6 digits long,
                the user is taken back to the menu
        99 - open the file "accounts.dat" in read binary(+) mode
        100-101 - determine the size of "accounts.dat" in number of bytes,
                then divide that by the size of one struct bank_account in
                number of bytes to get the number of bank accounts stored
        102-106 - if the file fails to open, terminate the program
        107 - ask the user how much they would like to withdraw
        108 - make sure we start at the top of the file
        109-124 - as long we haven't reached the end of the file, we search for
                the account that corresponds with the account number the user
                entered, then we copy the entire account back into the file
                while updating the balance by subtracting the withdrawal
		amount and set 'found' to 1. however, if the account number
		does not correspond to any stored accounts, 'found' will equal
		0.
        125-129 - if 'found' = 0, then it will report that the account was not
                found and return to the menu
        130 - close the file stream
Lines 132-186:
	If the user selects '3', they will be prompted to create an account
	135 - declare variables
	136 - open the file "accounts.dat" in append binary(+) mode
        137-138 - determine the size of "accounts.dat" in number of bytes,
                then divide that by the size of one struct bank_account in
                number of bytes to get the number of bank accounts stored
        139-143 - if the file fails to open, terminate the program
	146-153 - if it opens, we ask the user to input their first, last,
		and middle names, and ask to create their account number
        154 - determine the length of the account number (if m = 123456, r = 6)
        155 - set variable 'try' to 0
	156-160 - if the account number is more or less than 6 digits long,
                the user is taken back to the menu
	161-176 - if the account number has already been taken by another
		account, alert the user and set 'try' to 1
	177-178 - if 'try' is 1, return to main menu
	179-180 - ask the user to input their beginning balance
	181-183 - write the new account to the file "accounts.dat"
	184 - close the file stream
Lines 187-230:
	If the user selects '4', the user may delete an account
	189 - Create file pointer to a temorary file
	191-192 - ask the user for their account number
        193 - determine the length of the account number (if m = 123456, r = 6)
        194-198 - if the account number is more or less than 6 digits long,
                the user is taken back to the menu
	199 - open the file "accounts.dat" in read binary mode
	200-204 - if the file fails to open, terminate the program
	205 - open the file "tmp.dat" in write binary mode
	206-210 - if the file fails to open, terminate the program
	211-218 - until we reach the end of the file, we search for the
		account that corresponds to the account number given. if it is
		found, we set and 'found' to 1 and skip over that account while 
		we write the rest of the contents of "accounts.dat" to "tmp.dat"
	219-221 - if 'found' = 0, then it will report that the account was not
                found and return to the menu
	222-223 - close the file streams ("accounts.dat" and "tmp.dat")
	225-226 - delete "accounts.dat" and rename "tmp.dat" to "accounts.dat"
Lines 229-254:
	If the user selects '5', display one individual account
        231 - open the file "accounts.dat" in append binary mode
        232-233 - determine the size of "accounts.dat" in number of bytes,
                then divide that by the size of one struct bank_account in
                number of bytes to get the number of bank accounts stored
        234-238 - if the file fails to open, terminate the program
	239-240 - ask the user for their account number
        241 - determine the length of the account number (if m = 123456, r = 6)
        242-246 - if the account number is more or less than 6 digits long,
                the user is taken back to the menu
	248-252 - display the account that corresponds to the account number
Lines 255-277:
	If the user selects '6', display all accounts stored

				**************
				END OF PROGRAM
				**************
