#pragma once

#include <iostream>

#include "clsPerson.h"
#include "DataStructures.h"
#include "clsCard.h"

using namespace std;
class clsPassenger {
protected:
	string name;
	int id;
	clsCard* Card;

public:
	Passenger(string name, int id, Card* card)
		: name(name), id(id), card(card) {}

       bool operator==(int id){
        return this->id==id;
      }
};
