// InheritanceConsoleApplication.cpp 

#include <iostream>
#include "SavingBankAccount.h"

int main()
{
    BankAccount b;
    b.AccountInformation();

    SavingBankAccount savingBankAccount(100, "Ewa Nowak", "z�", 0.12);
    savingBankAccount.AccountInformation();

    
}