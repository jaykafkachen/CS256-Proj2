// CS256-Proj2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bankacct.h"
#include "savings.h"
#include "checking.h"
#include <iostream>
using namespace std;

int main()
{
	Savings s(0.0, 0.1, false);
	cout << "Savings Account Test: " << endl;
	char choice;
	do
	{
		cout << "\n1 - Deposit\n2 - Withdraw\n3 - Check balance\n4 - End month\n-->";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			double d;
			cout << "\nAmount to deposit: $";
			cin >> d;
			s.Savings::deposit(d);
			break;
		}
		case '2':
		{
			double w;
			cout << "\nAmount to withdraw: $";
			cin >> w;
			s.Savings::withdraw(w);
			break;
		}
		case '3':
			cout << "Current balance: $" << s.getBalance() << endl;
			break;
		case '4':
			break;
		default:
			cout << "Invalid input" << endl;
		}
	} while (choice != '4');
	s.Savings::monthlyProc();

	Checking c(0.0, 0.05);
	cout << "\nChecking Account Test: " << endl;
	do
	{
		cout << "\n1 - Deposit\n2 - Withdraw\n3 - Check balance\n4 - End month\n-->";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			double d;
			cout << "\nAmount to deposit: $";
			cin >> d;
			c.Checking::deposit(d);
			break;
		}
		case '2':
		{
			double w;
			cout << "\nAmount to withdraw: $";
			cin >> w;
			c.Checking::withdraw(w);
			break;
		}
		case '3':
			cout << "Current balance: $" << c.getBalance() << endl;
			break;
		case '4':
			break;
		default:
			cout << "Invalid input" << endl;
		}
	} while (choice != '4');
	c.Checking::monthlyProc();

    return 0;
}

/*Bank Accounts

Write a complete program that demonstrates these classes by asking the user to enter
the amounts of deposits and withdrawals for a savings account and checking account.

The program should display statistics for the month, including beginning balance, total
amount of deposits, total amount of withdrawals, service charges, and ending balance. */