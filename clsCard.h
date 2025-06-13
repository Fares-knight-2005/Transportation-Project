#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"

using namespace std;
class clsCard {

protected:
	bool type;
	double balance;


public:
	clsCard(bool type = false, int balance = 0) {
		this->type = type;
		this->balance = balance;
	}

        clsCard(string type = "Reguler", int balance = 0) {
		if(type=="Reguler")
			this.type=false;
		else
			this.type=true;
		this->balance = balance;
	}

	void payment(double amount) {
		if (balance >= amount) {
			balance -= amount;
		}
	}

	void recharge(double amount) {
		balance += amount;
	}

	double getBalance()  {
		return balance;
	}


        string getType(){
        return type ? "Premium" : "Regular";
        }

       string toString(){
        ostringstream oss;
        oss << (type ? "Premium" : "Regular") << ",,," << balance;
        return oss.str();
       }



};

