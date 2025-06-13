#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"
#include "clsVehicle.h"
#include <sstream>

class clsTransportLine
{


public:
    clsTransportLine(int numberOfVehicles, double price, enVehicleType vehiclesType, DoubleLinkedList<clsStation> stations) :
        stations(stations), pricePerKilometer(price), id(++numberOfAllTransportLine), vehiclesType(vehiclesType),
        numberOfVehicles(numberOfVehicles) {
    }

    clsTransportLine(int id,int numberOfVehicles, double price, enVehicleType vehiclesType, DoubleLinkedList<clsStation> stations) :
         id(id),stations(stations), pricePerKilometer(price), vehiclesType(vehiclesType),
         numberOfVehicles(numberOfVehicles) {
    }

    clsTransportLine() :id(0), numberOfVehicles(0), price(0) {}

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
            return  station.getHead();
    }

    bool operator==(int id) {
        return this->id == id;
    }

    int getId(){
        return id;
    }

    void display() {

        cout << "\nTransport Line Information\n";
        cout << "--------------------------\n";
        cout << "Line ID: " << id << "\n";
        cout << "Number of Vehicles: " << numberOfVehicles << "\n";
        cout << "Price : " << price << " $\n";
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
        oss << id << ",,," << numberOfVehicles << ",,," << price << ",,," << static_cast<int>(vehiclesType) << ",,,";
        for (int i = 0; i < stations.size(); i++)
            oss << ",,," << stations[i];
        return oss.str();
    }

    clsTransportLine parse(string line,OpenHash<int, clsStation>& stations) {
    DoubleLinkedList<string> tokens = Split(line,",,,");
    if (tokens.size() < 4) {
        throw invalid_argument("Not enough tokens in line");
    }

    int id = stoi(tokens[0]);
    int vehicles = stoi(tokens[1]);
    double price = stod(tokens[2]);
    enVehicleType type = static_cast<enVehicleType>(stoi(tokens[3]));
    
    DoubleLinkedList<clsStation> stationList;
    for (int i = 4; i < tokens.size(); i++) {
        int stationId = stoi(tokens[i]);
        stationList.addFirst(stations[stationId]);
    }

    clsTransportLine tl(vehicles, price, type, stationList);
    tl.setid(id);
    return tl;
}


private:
    DoubleLinkedList<clsStation> stations;
    int id,numberOfVehicles,price;
    enVehicleType vehiclesType;
    static int numberOfAllTransportLine;

};
int clsTransportLine::numberOfAllTransportLine = 0;

#endif // TRANSPORTLINE_H
