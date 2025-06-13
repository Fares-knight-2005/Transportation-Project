#include<iostream>
#include "passengerTrip.h"

class clsVehicleTrip{


struct strVehicleMovements{
int idStation;
int currDisabilitSeat,currPackageSize;
SingleLinkedList<passengerTrip>> passenger;
int currDisabilitSeat,currPackageSize;
SingleLinkedList<passengerTrip>> passenger;

strVehicleMovements(int idStation):idStation(idStation),currPackageSize(0),currDisabilitSeat(0) {}
strVehicleMovements():idStation(0),currPackageSize(0),currDisabilitSeat(0) {}

};

int id;
ClosedHash<int,strVehicleMovements> vehicleMovements;
static int numberOfAllVehicleTrip;

public:
clsVehicleTrip():id(++numberOfAllVehicleTrip) {}

clsVehicleTrip(int id):id(id) {}

int getId(){
      return id;
}




};
int VehicleTrip::numberOfAllVehicleTrip=0;
