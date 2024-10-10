#pragma once


class BankAccount
{
public:
	double balance;
	std::string owner;
	std::string currency;

	void AccountInformation();

	void DepositToAccount(double amount);
	bool WidthdrawalFromAccount(double amount);
	void TransferBetweenAccounts(BankAccount& targetAcccount, double amount);
};