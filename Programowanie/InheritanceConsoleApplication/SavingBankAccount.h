#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
protected:
	double interestRate;

public:

	SavingBankAccount()// : BankAccount() //to jest domy�lne
	{
		interestRate = 0.1;
	}

	SavingBankAccount(double b, std::string o, std::string c, double ir) : BankAccount(b, o, c)
	{
		interestRate = ir;
	}


	void CalculateInterestRate()
	{
		balance = balance + balance * interestRate;
	}

	void AccountInformation()
	{
		/*std::cout << "Informacja o koncie bankowym\n";
		std::cout << "W�a�ciciel: " << owner << "\n";
		std::cout << "Saldo: " << balance << " " << currency << "\n";*/
		BankAccount::AccountInformation();
		std::cout << "Oprocentowanie " << interestRate << "\n";
	}
};


