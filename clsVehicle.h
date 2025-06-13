#ifndef CLSVEHICLE_H
#define CLSVEHICLE_H
#include <iostream>
#include "DataStructures.h"
#include "clsPassengerTrip.h"
#include <sstream>

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

class VehicleTrip{

struct VehicleMovements{
int idStation;
int currDisabilit,currPackageSize;
SingleLinkedList<passengerTrip>> p;
};

int id,idVehicle;
ClosedHash<int,VehicleMovements> m;
public:

int getId(){
      return id;
}


};

    bool hasDisabilityAccess() {
        return disabilitySeats>currDisabilitySeats;
    }

    bool hasCapacity(){
        return  capacity>currSeats;
    }

    bool hasPackageSize(){
        return  packageSize>currPackageSize;
    }

void starVehicleTrip(clsTransportLine t,clsPassengerTrip &v){


    DoubleNode<clsStation> *station=t.getFirstStation.getHead();
    destination=true;
    
    while(station!=nullptr||destination){
      clsParking *parking=station->item->parkings[t.getId()];
      parking->vehicle.enqueue(this);
      Stack<clsPassengerTrip> s;
        
      if(parking->vehicle.size()==1){
          
      while(hasCapacity()&&!(parking->passengers.isEmpty())){
      passengerTrip trip=parking->passengers.dequeue();
      if(trip.getDestination()==destination&&(!trip.getDisability||hasDisabilityAccess())&&(!tripe.getThings()||hasPackageSize())){
      if(v.m[tripe.getIdEndStation()]==nullptr)
          v.m[tripe.getIdEndStation()]=ClosedHash<int,SingleLinkedList<VehicleMovements>>();
          
      v.m[tripe.getIdEndStation()].p.addFirst(trip);
      currSeats++; 
      if(trip.getDisability)
      {
      v.m[tripe.getIdEndStation()].currDisability++;
      currDisabilitySeats++;
      }
      if(trip.getThings())
      {
      v.m[tripe.getIdEndStation()].currPackageSize++;
      currPackageSize++;
      }
      }
      else
          s.push(trip);
      }
      if(!s.isEmpty())
          s.toQueue(parking->passengers);
      if(v.m[parking.getIdStation()]!=nullptr)
      {
      currSeats-=v.m[parking.getIdStation()].p.size();
      currDisabilitySeats-=v.m[parking.getIdStation()].CurrDisability;
      v.m[parking.getIdStation()].CurrDisability=0;
      currPackageSize-=v.m[parking.getIdStation()].CurrPackageSize;
      currPackageSize-=v.m[parking.getIdStation()].CurrPackageSize=0;
      } 
     if(station->next==nullptr)
          destination=false;  
      if(destination)
          station=station->next;
      else
          station=station->previous;
      parking->vehicle.dequeue();   
      }   
    }

vehicleTripId.addFirst(v.getId());
}

class clsVehicle {
public:
    clsVehicle(int id,enVehicleType type, int lineId, int cap, float spd, int disabilitySeats, int pkgSize) {
        this->id=id;
        vehicleType = type;
        transportLineId = lineId;
        capacity = cap;
        speed = spd;
        seatsForPeopleWithDisabilities = disabilitySeats;
        packageSize = pkgSize;
    }
    clsVehicle(enVehicleType type, int lineId, int cap, float spd, int disabilitySeats, int pkgSize) {
        vehicleType = type;
        transportLineId = lineId;
        capacity = cap;
        speed = spd;
        seatsForPeopleWithDisabilities = disabilitySeats;
        packageSize = pkgSize;
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
    void setId(int id){this->id=id;}

    void displayVehicleInfo() {
        cout << "\nVehicle Information:";
        cout<< "\nId: "<<id;
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

    string toString() {
    ostringstream oss;
    oss << static_cast<int>(vehicleType) << ",,,"  << transportLineId << ",,," 
        << capacity << ",,," << speed << ",,," << disabilitySeats << ",,," << packageSize<<",,,"<<id;
    
    Node<int>* current = vehicleTripId.getHead();
    while (current != nullptr) {
        oss << ",,," << current->data;
        current = current->next;
    }
    
    return oss.str();
  }

private:
    int id,transportLineId;
    int capacity,currSeats;
    float speed;
    int disabilitySeats,currDisabilitySeats;
    int packageSize,currPackageSize;
    bool destination;
    SingleLinkedList<int> vehicleTripId;
    static int numberOfAllVehicle;
};
int clsVehicle::numberOfAllVehicle=0;

#endif // CLSVEHICLE_H
      
