#include "checking_account.h"
#include "savings_account.h"
#include "atm.h"
#include <iostream>
#include <vector>
#include <memory>

using std::cout; using std::cin; using std::vector; using std::unique_ptr; using std::make_unique;

int main()
{
	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(100);
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);

	vector<unique_ptr<BankAccount>> acts;
	acts.push_back(std::move(s));
	acts.push_back(std::move(c));

	Customer cust(acts);
	ATM atm(cust);

	//some interaction..w customer
	cout << atm;

	return 0;
}