#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount()
{
	balance = 1000;
	owner = "Nieznany";
	currency = "z³";
}

BankAccount::BankAccount(double b, std::string o, std::string c)
{
	//balance = b;
	SetBalance(b);
	owner = o;
	currency = c;
}

void BankAccount::SetBalance(double b)
{
	if (b >= 0
		&& isSetBalanceExecute == false) //aby mozna by³o tylko raz wykonaæ kod
	{
		balance = b;

		isSetBalanceExecute = true;
	}
}

double BankAccount::GetBalance()
{
	//instrukcje zabezpieczaj¹ce
	return balance;
}

void BankAccount::AccountInformation()
{
	std::cout << "Informacja o koncie bankowym\n";
	std::cout << "W³aœciciel: " << owner << "\n";
	std::cout << "Saldo: " << balance << " " << currency << "\n";
}

void BankAccount::DepositToAccount(double amount)
{
	if (amount >= 0)
		balance = balance + amount;
}

bool BankAccount::WidthdrawalFromAccount(double amount)
{
	if (amount >= 0
		&& balance >= amount)
	{
		balance = balance - amount;
		return true;
	}

	return false;
}

void BankAccount::TransferBetweenAccounts(BankAccount& targetAcccount, double amount)
{
	if (WidthdrawalFromAccount(amount))
		targetAcccount.DepositToAccount(amount);

}