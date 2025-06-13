#ifndef PARKING_H
#define PARKING_H
#include "DataStructures.h"
#include "clsVehicle.h"
#include "clsPassenger.h"

class clsParking{
     
    public:
    clsParking():id(0),distanceToNext(0.0) {}
    clsParking(int id, double distanceToNext) :id(id), distanceToNext(distanceToNext) {}

    double getDistanceToNext(){
        return distanceToNext;
    }

    bool operator==(int id){
        return this->id==id;
    }

    private:
        Queue<clsVehicle> vehicl;
        Queue<clsPassenger> passengers;
        int id;
        double distanceToNext;
        enVehicleType parkingType;
        static int numberOfAllParking;
};
int clsParking::numberOfAllParking=0;

#endif // PARKING_H
