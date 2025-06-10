#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"

using namespace std;

class VIPCard : public Card {
public:
    VIPCard(double balance = 0)
        : Card("VIP", balance) {}

    void payment(double amount) override {
        double discounted = amount * 0.5; //discount 50%
        Card::deductFare(discounted);
       }

    void FreeRide() {
            return;
    }


};
