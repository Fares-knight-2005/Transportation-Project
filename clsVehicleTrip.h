#include<iostream>
#include "passengerTrip.h"
#include <sstream>

using namespace std;

class clsVehicleTrip{


struct strVehicleMovements{
int idStation;
int currDisabilitSeat,currPackageSize;
SingleLinkedList<passengerTrip>> passenger;

strVehicleMovements(int idStation):idStation(idStation),currPackageSize(0),currDisabilitSeat(0) {}
strVehicleMovements():idStation(0),currPackageSize(0),currDisabilitSeat(0) {}

        string toString() {
            ostringstream oss;
            oss << idStation ;
            
            auto current = passenger.getHead();
            while (current != nullptr) {
                oss <<",,,"<<current->data.toString();
                current = current->next;
            }
            
            return oss.str();
        }
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
    string toString() {
        ostringstream oss;
        oss << id;
            
        for(int i=0;i<passenger.size(),i++){
        Node<int,strVehicleMovements> current = passenger.getNode(i);
        while (current != nullptr) {
            oss << ",,," << current->data.toString();
        }
        }
        return oss.str();
    }

    void displayInfo() {
    cout << "**************************************\n";
    cout << "       Vehicle Trip Information      \n";
    cout << "**************************************\n";
    cout << "Trip ID: " << id << "\n";
    cout << "Total Vehicle Trips: " << numberOfAllVehicleTrip << "\n\n";

    for (int i = 0; i < vehicleMovements.size(); i++) {
        auto node = vehicleMovements.getNode(i);
        if (node.nodeType == ClosedNode<int, strVehicleMovements>::FULL) {
            cout << "Current Station: " << node.item.idStation << "\n";
            cout << "Passengers List:\n";
            cout << "----------------\n";

            auto current = node.item.passenger.getHead();
            int passengerCount = 1;
            
            while (current != nullptr) {
                cout << passengerCount++ << ". ";
                current->data.displayInfo();
                cout << "----------------\n";
                current = current->next;
            }
            cout << "**************************************\n";
        }
    }
    }



};
int VehicleTrip::numberOfAllVehicleTrip=0;
