#pragma once
#ifndef _SAVINGS_H
#define _SAVINGS_H

#include <iostream>
using namespace std;
#include "stdafx.h"
#include "bankacct.h"

class Savings : public BankAcct
{
protected:
	bool status; //true = active, false = inactive

public:
	Savings(double bal, double rt, bool stat) : BankAcct(bal, rt), status(stat) {}
	void checkStatus();
	virtual void deposit(double amt);
	virtual void withdraw(double amt);
	virtual void monthlyProc();
	virtual void statement();
};

void Savings::checkStatus()
{
	if (getBalance() < 25)
		status = false;
	else
		status = true;
}

void Savings::deposit(double amt)
{
	BankAcct::deposit(amt);
	checkStatus(); //will automatically set status to active when balance reaches 25
}

void Savings::withdraw(double amt)
{
	checkStatus();
	if (status == true && amt < getBalance())
		BankAcct::withdraw(amt);
	else if (amt > getBalance())
		cout << "Overdraft attempt averted, cannot withdraw $" << amt << endl; //assignment did not specify this,
	else                                                                       //but w/o it can withdraw any overdraft amt fr savings
		cout << "Account is inactive." << endl;
}

void Savings::monthlyProc()
{
	int wd = getWithdrawals();
	if (wd > 4)
		addCharge((double)(wd - 4));
	checkStatus();
	Savings::statement();
	BankAcct::monthlyProc();
}

void Savings::statement()
{
	BankAcct::statement();
	cout << "Account status: ";
	if (status == true)
		cout << "Active" << endl;
	else
		cout << "Inactive" << endl;
}

/*Next, design a savings account class, derived from the generic account class. The savings
account class should have the following additional member:
status (to represent an active or inactive account) 

If the balance of a savings account falls below $25, it becomes inactive. (The status
member could be a flag variable.) No more withdrawals may be made until the balance
is raised above $25, at which time the account becomes active again. The savings
account class should have the following member functions:

withdraw: A function that checks to see if the account is inactive before a withdrawal
is made. (No withdrawal will be allowed if the account is not
active.) A withdrawal is then made by calling the base class version of
the function.

deposit: A function that checks to see if the account is inactive before a deposit
is made. If the account is inactive and the deposit brings the balance
above $25, the account becomes active again. The deposit is then
made by calling the base class version of the function.

monthlyProc: Before the base class function is called, this function checks the number
of withdrawals. If the number of withdrawals for the month is more than 4, a service charge 
of $1 for each withdrawal above 4 is added to the base class variable that holds the monthly service charges.
(Don’t forget to check the account balance after the service charge is taken. If the balance 
falls below $25, the account becomes inactive.) */

#endif