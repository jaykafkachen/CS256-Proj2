#pragma once
#ifndef _BANKACCT_H
#define _BANKACCT_H

#include <iostream>
using namespace std;
#include "stdafx.h"

class BankAcct
{
public:
	BankAcct(double bal, double rt);
	virtual void statement();
	virtual void deposit(double amt);
	virtual void withdraw(double amt);
	virtual void monthlyProc();
	double calcInt();
	void addCharge(double amt);
	double getBalance();
	int getWithdrawals();
	int getDeposits();

protected:
	double balance;
	double rate;
	int deposits = 0;
	int withdrawals = 0;
	double charge = 0;
};

BankAcct::BankAcct(double bal, double rt): balance(bal), rate(rt) {}

void BankAcct::statement()
{
	cout << "Monthly Bank Statement: " << endl;
	cout << "Beginning Balance: $" << balance << endl;
	cout << "Number of deposits: " << deposits << endl;
	cout << "Number of withdrawals: " << withdrawals << endl;
	cout << "Total monthly charges: $" << charge << endl;
}

void BankAcct::deposit(double amt)
{
	balance += amt;
	deposits++;
	cout << "Deposit of $" << amt << " successful" << endl;
}

void BankAcct::withdraw(double amt)
{
	balance -= amt;
	withdrawals++;
	cout << "Withdrawal of $" << amt << " successful" << endl;
}

double BankAcct::calcInt()
{
	double monthly = rate / 12;
	monthly *= balance;
	balance += monthly;
	return monthly;
}

void BankAcct::monthlyProc()
{
	balance -= charge;
	cout << "Monthly interest: $" << calcInt() << endl;
	cout << "Current Balance: $" << balance << endl;
	withdrawals = 0;
	deposits = 0;
	charge = 0;
}

void BankAcct::addCharge(double amt)
{
	charge += amt;
}

double BankAcct::getBalance()
{
	return balance;
}

int BankAcct::getWithdrawals()
{
	return withdrawals;
}

int BankAcct::getDeposits()
{
	return deposits;
}

/*Design a generic class to hold the following information about a bank account:
Balance
Number of deposits this month
Number of withdrawals
Annual interest rate
Monthly service charges

The class should have the following member functions:
Constructor : Accepts arguments for the balance and annual interest rate.

deposit: A virtual function that accepts an argument for the amount of the
deposit. The function should add the argument to the account balance.
It should also increment the variable holding the number of deposits.

withdraw: A virtual function that accepts an argument for the amount of the
withdrawal. The function should subtract the argument from the
balance. It should also increment the variable holding the number of
withdrawals.

calcInt: A virtual function that updates the balance by calculating the monthly
interest earned by the account, and adding this interest to the balance.
This is performed by the following formulas:
Monthly Interest Rate = (Annual Interest Rate / 12)
Monthly Interest = Balance * Monthly Interest Rate
Balance = Balance + Monthly Interest

monthlyProc: A virtual function that subtracts the monthly service charges from the
balance, calls the calcInt function, and then sets the variables that
hold the number of withdrawals, number of deposits, and monthly
service charges to zero.*/

#endif