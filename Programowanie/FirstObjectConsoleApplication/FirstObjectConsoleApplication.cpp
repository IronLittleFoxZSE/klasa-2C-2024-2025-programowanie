// FirstObjectConsoleApplication.cpp 

#include <iostream>

class BankAccount
{
public:
	double balance;
	std::string owner;
	std::string currency;

	void AccountInformation()
	{
		std::cout << "Informacja o koncie bankowym\n";
		std::cout << "W³aœciciel: " << owner << "\n";
		std::cout << "Saldo: " << balance << " " << currency << "\n";
	}

	void DepositToAccount(double amount)
	{
		if (amount >= 0)
			balance = balance + amount;
	}

	bool WidthdrawalFromAccount(double amount)
	{
		if (amount >= 0
			&& balance >= amount)
		{
			balance = balance - amount;
			return true;
		}

		return false;
	}
};

void transferBetweenAccounts(BankAccount& sourceAccount, BankAccount& targetAcccount, double amount)
{
	if (sourceAccount.WidthdrawalFromAccount(amount))
		targetAcccount.DepositToAccount(amount);

}

int main()
{
	BankAccount firstAccount;
	firstAccount.balance = 7200;
	firstAccount.owner = "Jan Kowalski";
	firstAccount.currency = "z³";

	firstAccount.AccountInformation();

	//accountInformation(firstAccount);

	BankAccount secondAccount;
	secondAccount.balance = 3200;
	secondAccount.owner = "Ewa Nowak";
	secondAccount.currency = "z³";

	secondAccount.AccountInformation();

	firstAccount.DepositToAccount(100);
	firstAccount.AccountInformation();

	firstAccount.WidthdrawalFromAccount(200);
	firstAccount.AccountInformation();
	secondAccount.AccountInformation();

	transferBetweenAccounts(firstAccount, secondAccount, 8100);

	firstAccount.AccountInformation();
	secondAccount.AccountInformation();

}
