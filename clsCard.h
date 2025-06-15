#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"
#include <sstream>

using namespace std;
class clsCard {

protected:
	bool type;
	double balance;
        int freeTrips;
        static double amountForFreeTrip;


public:
	clsCard(bool type = false, int balance = 0,int freeTrips=0) {
		this->type = type;
		this->balance = balance;
		this->freeTrips = freeTrips;
	}

        clsCard(string type = "Reguler", int balance = 0) {
		if(type=="Reguler")
			this.type=false;
		else
			this.type=true;
		this->balance = balance;
	}

	bool payment(double amount) {
		if (balance >= amount) {
			balance -= amount;
			return true;
		}
		else
			return false;
	}

	void recharge(double amount) {
		balance += amount;
		if(amount==amountForFreeTrip)
			freeTrips++;
	}

	double getBalance()  {
	return balance;
	}


        string getType(){
        return type ? "Premium" : "Regular";
        }

       string toString(){
        ostringstream oss;
        oss << (type ? "Premium" : "Regular") << ",,," << balance<< ",,," <<freeTrips;
        return oss.str();
       }


       static void setAmountForFreeTrip(int amount){
        amountForFreeTrip = amount; 
       }

       double getAmountForFreeTrip(){
        return amountForFreeTrip;
       }


};
double clsCard::amountForFreeTrip=2000;
