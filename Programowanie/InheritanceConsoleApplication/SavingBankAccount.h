#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
protected:
	double interestRate;

public:

	SavingBankAccount()// : BankAccount() //to jest domyœlne
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
};