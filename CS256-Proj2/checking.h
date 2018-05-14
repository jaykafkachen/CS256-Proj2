#pragma once
#ifndef _CHECKING_H
#define _CHECKING_H

#include <iostream>
using namespace std;
#include "stdafx.h"
#include "bankacct.h"

class Checking : public BankAcct
{
public: 
	Checking(double bal, double rt) : BankAcct(bal, rt) {}
	virtual void withdraw(double amt);
	virtual void monthlyProc();
};

void Checking::withdraw(double amt)
{
	if (getBalance() - amt < 0)
	{
		addCharge(15); //this will automatically add charge to service charge to be taken from monthlyProc
		cout << "Account balance below amount requested. Overdraft charge of $15 added to monthly charges." << endl;
	}
	else
		BankAcct::withdraw(amt);
}

void Checking::monthlyProc()
{
	addCharge(5 + (0.1*getWithdrawals()));
	BankAcct::statement();
	BankAcct::monthlyProc();
}

/*Next, design a checking account class, also derived from the generic account class. 

It should have the following member functions:

withdraw: Before the base class function is called, this function will determine if a
withdrawal (a check written) will cause the balance to go below $0. If
the balance goes below $0, a service charge of $15 will be taken from
the account. (The withdrawal will not be made.) If there isn’t enough
in the account to pay the service charge, the balance will become negative
and the customer will owe the negative amount to the bank.

monthlyProc: Before the base class function is called, this function adds the monthly
fee of $5 plus $0.10 per withdrawal (check written) to the base class
variable that holds the monthly service charges.*/

#endif