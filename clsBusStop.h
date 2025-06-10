
#pragma once

#include <iostream>
#include "DataStructures.h"
#include "Bus.h"
#include "Passenger.h"


using namespace std;

class ParkingQueue
{
public:

    bool operator==(int id)
    {
        return this->id == id;
    }


private:

    Queue<Bus> buses;
    Queue<Passenger> passengers;
    int MaxVehiclesNum;
    static int numberOfAllParkingQueue;
};


class clsBusStop {

public:

    bool operator==(int id) {
        return this->id == id;
    }
private:
    ParkingQueue  departure;
    ParkingQueue  coming;
    int id;
    static int numberOfAllStation;
};
int Station::numberOfAllStation = 0;


