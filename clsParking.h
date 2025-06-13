#ifndef PARKING_H
#define PARKING_H
#include "DataStructures.h"
#include "clsVehicle.h"
#include "clsPassengerTrip.h"
#include <sstream>

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

    int getStationId(){
        return stationId;    
    }

    string toString() {
    ostringstream oss;
    oss<< id<< ",,,"<< stationId<< ",,," << distanceToNext << ",,,"  << static_cast<int>(parkingType);
    return oos;
    }
    private:
        Queue<clsVehicle> vehicl;
        Queue<clsPassengerTrip> passengers;
        int id,stationId;
        double distanceToNext;
        enVehicleType parkingType;
        static int numberOfAllParking;
};
int clsParking::numberOfAllParking=0;

#endif // PARKING_H
