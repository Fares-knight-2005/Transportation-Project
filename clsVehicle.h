#ifndef CLSVEHICLE_H
#define CLSVEHICLE_H
#include <iostream>
#include "DataStructures.h"

using namespace std;


enum enVehicleType {BUS=1, TRAM, FERRY, METRO};

string getVehicleType(enVehicleType vehicleType) {
    switch(vehicleType) {
        case BUS:  return "BUS";
        case TRAM: return "TRAM";
        case FERRY: return "FERRY";
        default: return "METRO";
    }
}

enVehicleType setVehicleType(int vehicleNumber){
    switch(vehicleNumber){
        case 1: return BUS;
        case 2: return TRAM;
        case 3: return FERRY;
        default: return METRO;
    }
}

class clsVehicle {
public:
    clsVehicle(enVehicleType type, int lineId, int cap, float spd, int disabilitySeats, int pkgSize) {
        vehicleType = type;
        transportLineId = lineId;
        capacity = cap;
        speed = spd;
        seatsForPeopleWithDisabilities = disabilitySeats;
        packageSize = pkgSize;
    }

    int getId()
    {
        return id;
    }

    enVehicleType getVehicleType() { return vehicleType; }
    int getTransportLineId() { return transportLineId; }
    int getCapacity() { return capacity; }
    float getSpeed() { return speed; }
    int getDisabilitySeats() { return seatsForPeopleWithDisabilities; }
    int getPackageSize() { return packageSize; }

    void setVehicleType(enVehicleType type) { vehicleType = type; }
    void setTransportLineId(int lineId) { transportLineId = lineId; }
    void setCapacity(int cap) { capacity = cap; }
    void setSpeed(float spd) { speed = spd; }
    void setDisabilitySeats(int seats) { seatsForPeopleWithDisabilities = seats; }
    void setPackageSize(int size) { packageSize = size; }

    void displayVehicleInfo() {
        cout << "\nVehicle Information:";
        cout << "\nType: " << ::getVehicleType(vehicleType);
        cout << "\nTransport Line ID: " << transportLineId;
        cout << "\nCapacity: " << capacity;
        cout << "\nSpeed: " << speed << " km/h";
        cout << "\nDisability Seats: " << seatsForPeopleWithDisabilities;
        cout << "\nPackage Size: " << packageSize << endl;
    }

    bool hasDisabilityAccess() {
        return seatsForPeopleWithDisabilities > 0;
    }

    bool canAccommodatePackage(int packageSizeToCheck) {
        return packageSizeToCheck <= packageSize;
    }

private:
    int id;
    enVehicleType vehicleType;
    int transportLineId;
    int capacity;
    float speed;
    int seatsForPeopleWithDisabilities;
    int packageSize;
};

#endif // CLSVEHICLE_H
      
