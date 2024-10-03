#include <iostream>

struct BankAccount
{
	double balance;
	std::string owner;
	std::string currency;
};

void accountInformation(BankAccount &account)
{
	std::cout << "Informacja o koncie bankowym\n";
	std::cout << "W³aœciciel: " << account.owner << "\n";
	std::cout << "Saldo: " << account.balance << " " << account.currency << "\n";
}

void depositToAccount(BankAccount &account, double amount)
{
	if (amount >= 0)
		account.balance = account.balance + amount;
}

bool widthdrawalFromAccount(BankAccount& account, double amount)
{
	if (amount >= 0
		&& account.balance >= amount)
	{
		account.balance = account.balance - amount;
		return true;
	}

	return false;
}

void transferBetweenAccounts(BankAccount &sourceAccount, BankAccount &targetAcccount, double amount)
{
	if (widthdrawalFromAccount(sourceAccount, amount))
		depositToAccount(targetAcccount, amount);

}

void task4()
{
	BankAccount firstAccount;
	firstAccount.balance = 7200;
	firstAccount.owner = "Jan Kowalski";
	firstAccount.currency = "z³";

	accountInformation(firstAccount);

	BankAccount secondAccount;
	secondAccount.balance = 3200;
	secondAccount.owner = "Ewa Nowak";
	secondAccount.currency = "z³";

	accountInformation(secondAccount);

	depositToAccount(firstAccount, 100);
	accountInformation(firstAccount);

	widthdrawalFromAccount(firstAccount, 200);
	accountInformation(firstAccount);
	accountInformation(secondAccount);

	transferBetweenAccounts(firstAccount, secondAccount, 8100);

	accountInformation(firstAccount);
	accountInformation(secondAccount);
}