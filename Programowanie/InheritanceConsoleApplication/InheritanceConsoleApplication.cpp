// InheritanceConsoleApplication.cpp 

#include <iostream>
#include "SavingBankAccount.h"

int main()
{
    SavingBankAccount savingBankAccount;
    savingBankAccount.DepositToAccount(1000);
    savingBankAccount.AccountInformation();
    savingBankAccount.CalculateInterestRate();
    savingBankAccount.AccountInformation();

    SavingBankAccount secondSavingBankAccount(100, "Ewa Nowak", "z³", 0.12);
}
