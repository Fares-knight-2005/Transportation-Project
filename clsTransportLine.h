#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"
#include "clsVehicle.h"
#include <sstream>

class clsTransportLine
{


public:
    clsTransportLine(int numberOfVehicles, double pricePerKilometer, enVehicleType vehiclesType, DoubleLinkedList<clsStation> stations) :
        stations(stations), pricePerKilometer(pricePerKilometer), id(++numberOfAllTransportLine), vehiclesType(vehiclesType),
        numberOfVehicles(numberOfVehicles) {
    }

    clsTransportLine(int id,int numberOfVehicles, double pricePerKilometer, enVehicleType vehiclesType, DoubleLinkedList<clsStation> stations) :
         id(id),stations(stations), pricePerKilometer(pricePerKilometer), vehiclesType(vehiclesType),
        numberOfVehicles(numberOfVehicles) {
    }

    clsTransportLine() :id(0), numberOfVehicles(0), pricePerKilometer(0) {}

    void addStation(clsStation station, int stationNumber) {
        stations.add(stationNumber - 1, station);
    }

    void removeStation(int stationId) {
        if (stations.remove(stationId))
            cout << "The deletion process was completed successfully.\n";
        else
            cout << "The station ID number you entered is not available.\n";
    }

    DoubleNode<clsStation> *getFirstStation(){
            return    station.getHead();
    }

    bool operator==(int id) {
        return this->id == id;
    }


    void display() {

        cout << "\nTransport Line Information\n";
        cout << "--------------------------\n";
        cout << "Line ID: " << id << "\n";
        cout << "Number of Vehicles: " << numberOfVehicles << "\n";
        cout << "Price per Kilometer: " << pricePerKilometer << " $\n";
        cout << getVehicleType(vehiclesType) << "\n";
        if (stations.size() > 0) {
            cout << "Stations IDs: ";
            for (int i = 0; i < stations.size(); i++) {
                cout << stations[i]->getid();
                if (i < stations.size() - 1)
                    cout << ", ";
            }
            cout << "\n";
        }
        cout << "--------------------------\n";


    }

    string toString() {
        ostringstream oss;
        oss << id << ",,," << numberOfVehicles << ",,," << pricePerKilometer << ",,," << static_cast<int>(vehiclesType) << ",,,";
        for (int i = 0; i < stations.size(); i++)
            oss << ",,," << stations[i];
        return oss.str();
    }


private:
    DoubleLinkedList<clsStation> stations;
    int id, numberOfVehicles, pricePerKilometer;
    enVehicleType vehiclesType;
    static int numberOfAllTransportLine;

};
int clsTransportLine::numberOfAllTransportLine = 0;

#endif // TRANSPORTLINE_H
