#pragma once

#include <iostream>

#include "clsPerson.h"
#include "DataStructures.h"
#include "clsCard.h"

using namespace std;
class clsPassenger : clsPerson {
protected:

    int id;
    clsCard* Card;

public:
    clsPassenger(short Age, string FirstName, string LastName, string PhoneNumber, string Email
        , int id, clsCard* card)
        : clsPerson(Age, FirstName, LastName, PhoneNumber, Email), id(id), Card(card) {
    }

    bool operator==(int id) {
        return this->id == id;
    }


    bool operator==(string fullName) {
        return this->GetFullName() == fullName;
    }
};