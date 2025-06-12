#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"

using namespace std;
class clsCard {

protected:
	string type;
	double balance;


public:
	clsCard(string type = "Reguler", int balance = 0) {
		this->type = type;
		this->balance = balance;
	}
	virtual void payment(double amount) {
		if (balance >= amount) {
			balance -= amount;
		}
		else {
		}
	}
	void recharge(double amount) {
		balance += amount;
	}

	double getBalance()  {
		return balance;
	}

	string getType()  {
		return type;
	}







};

