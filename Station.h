#ifndef STATION_H
#define STATION_H
#include "DataStructures.h"
#include "Bus.h"
#include "Passenger.h"

class ParkingQueue
{
    public:

    bool operator==(int id){
        return this->id==id;
    }
    private:
        Queue<Bus> buses;
        Queue<Passenger> passengers;
        int totalOfVehicles;
        int totalOfPassengers;
        int id;
        static int numberOfAllParkingQueue;
};
int ParkingQueue::numberOfAllParkingQueue=0;

class Station{

    public:

    bool operator==(int id){
        return this->id==id;
    }
    private:
        ParkingQueue  departure;
        ParkingQueue  coming;
        int id;
        static int numberOfAllStation;
};
int Station::numberOfAllStation=0;

#endif // STATION_H
