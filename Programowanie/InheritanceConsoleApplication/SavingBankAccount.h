#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
protected:
	double interestRate;

public:

	SavingBankAccount();
	SavingBankAccount(double b, std::string o, std::string c, double ir);


	void CalculateInterestRate();

	void AccountInformation();
};


