// FirstObjectConsoleApplication.cpp 

#include <iostream>
#include "BankAccount.h"

int main()
{
	BankAccount firstAccount(7200, "Jan Kowalski", "z�");
	//firstAccount.balance = 7200;
	//firstAccount.SetBalance(7200);
	//firstAccount.owner = "Jan Kowalski";
	//firstAccount.currency = "z�";

	firstAccount.AccountInformation();

	//accountInformation(firstAccount);

	BankAccount secondAccount(3200, "Ewa Nowak", "z�");
	//secondAccount.balance = 3200;
	//secondAccount.SetBalance(3200);
	//secondAccount.owner = "Ewa Nowak";
	//secondAccount.currency = "z�";

	secondAccount.AccountInformation();

	firstAccount.DepositToAccount(-100);
	firstAccount.AccountInformation();

	firstAccount.WidthdrawalFromAccount(200);
	firstAccount.AccountInformation();
	secondAccount.AccountInformation();

	firstAccount.TransferBetweenAccounts(secondAccount, 8100);

	firstAccount.AccountInformation();
	secondAccount.AccountInformation();

}
