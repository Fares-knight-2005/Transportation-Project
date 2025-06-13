#ifndef PARKING_H
#define PARKING_H
#include "DataStructures.h"
#include "clsVehicle.h"
#include "clsPassengerTrip.h"
#include <sstream>

class clsParking{
     
    public:
    clsParking():id(0),distanceToNext(0.0) {}
    clsParking(int id, double distanceToNext,int stationId,enVehicleType parkingType) :id(id), distanceToNext(distanceToNext),stationId(stationId),parkingType(parkingType) {}
     clsParking(double distanceToNext,int stationId,enVehicleType parkingType) :id(++numberOfAllParking), distanceToNext(distanceToNext),stationId(stationId),parkingType(parkingType) {
          
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

    clsParking parse(string& line) {
    DoubleLinkedList<string> tokens = Split(line,",,,");
         
    if (tokens.size() < 4) {
        throw invalid_argument("Not enough tokens in line");
    }

    int id = stoi(tokens[0]);
    int stationId = stoi(tokens[1]);
    double distance = stod(tokens[2]);
    enVehicleType type = static_cast<enVehicleType>(stoi(tokens[3]));

    return clsParking(id, distance, stationId, type);
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
