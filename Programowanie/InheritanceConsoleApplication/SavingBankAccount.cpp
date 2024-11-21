#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount()// : BankAccount() //to jest domyœlne
{
	interestRate = 0.1;
}

SavingBankAccount::SavingBankAccount(double b, std::string o, std::string c, double ir) : BankAccount(b, o, c)
{
	interestRate = ir;
}

void SavingBankAccount::CalculateInterestRate()
{
	balance = balance + balance * interestRate;
}

void SavingBankAccount::AccountInformation()
{
	/*std::cout << "Informacja o koncie bankowym\n";
	std::cout << "W³aœciciel: " << owner << "\n";
	std::cout << "Saldo: " << balance << " " << currency << "\n";*/
	BankAccount::AccountInformation();
	std::cout << "Oprocentowanie " << interestRate << "\n";
}