#pragma once

#include <iostream>

#include "clsPerson.h"
#include "DataStructures.h"
#include "clsCard.h"

using namespace std;

class clsPassenger :public clsPerson {
protected:

    clsCard Card;
    static int numberOfAllPassenger;
public:
    clsPassenger(short Age, string FirstName, string LastName, string PhoneNumber, string Email,
                 int id, clsCard* card)
        : clsPerson(Age, FirstName, LastName, PhoneNumber, Email), Card(card) {}

    string toString(){
        ostringstream oss;
        
        oss << id << ",,," << clsPerson::toString() << ",,,"<<card.toString();
        
        return oss.str();
    }
};
static int clsPassenger::numberOfAllPassenger;
