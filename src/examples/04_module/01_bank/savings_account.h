//savings_account.h
#include "bank_account.h"
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount() = default;
	SavingsAccount(int b) : BankAccount(b) {}
	int get_balance()const { return balance * (1.125); }
};

#endif //!SAVINGS_ACCOUNT_H
