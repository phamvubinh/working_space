#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accountNumber;
	double balance;
public:
	Account(int accountNumber, double balance = 0.0);
	int getAccountNumber() const;
	double getBalance() const;
	void setBalance(double Balance);
	void credit(double ammount);
	void debit(double amount);
	void print() const;
};

#endif