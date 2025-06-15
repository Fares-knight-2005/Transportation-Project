#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"
#include "clsVehicle.h"
#include <sstream>

class clsTransportLine
{
private:
    DoubleLinkedList<clsStation*> stations;
    string name;
    int id, numberOfVehicles;
    double price;
    enVehicleType vehicleType;
    static int numberOfAllTransportLines;

public:
    clsTransportLine(int numberOfVehicles, double price, enVehicleType vehicleType, string name, DoubleLinkedList<clsStation*> stations) :
        stations(stations), price(price), id(++numberOfAllTransportLines), vehicleType(vehicleType),
        numberOfVehicles(numberOfVehicles), name(name) {
    }

    clsTransportLine(int id, int numberOfVehicles, double price, enVehicleType vehicleType, string name, DoubleLinkedList<clsStation*> stations) :
         id(id), stations(stations), price(price), vehicleType(vehicleType),
         numberOfVehicles(numberOfVehicles), name(name) {
    }

    clsTransportLine() : id(0), numberOfVehicles(0), price(0) {}

    void addStation(clsStation* station, int stationNumber) {
        stations.add(stationNumber - 1, station);
    }

    void removeStation(int stationId) {
        if (stations.remove(stationId))
            cout << "The deletion process was completed successfully.\n";
        else
            cout << "The station ID number you entered is not available.\n";
    }

    DoubleNode<clsStation*>* getFirstStation(){
            return  stations.getHead();
    }

    bool operator==(int id) {
        return this->id == id;
    }

    int getId(){
        return id;
    }

    void setid(int id) {
        this->id = id;
    }

    void display() {
        cout << "\nTransport Line Information\n";
        cout << "--------------------------\n";
        cout << "Line ID: " << id << "\n";
        cout << "Line Name: " << name << "\n";
        cout << "Number of Vehicles: " << numberOfVehicles << "\n";
        cout << "Price : " << price << " $\n";
        cout << getVehicleType(vehicleType) << "\n";
        if (stations.size() > 0) {
            cout << "Stations IDs: ";
            for (int i = 0; i < stations.size(); i++) {
                cout << stations[i]->getId();
                if (i < stations.size() - 1)
                    cout << ", ";
            }
            cout << "\n";
        }
        cout << "--------------------------\n";
    }

    string toString() {
        ostringstream oss;
        oss << id << ",,," << numberOfVehicles << ",,," << price << ",,," << static_cast<int>(vehicleType) << ",,," << name;
        for (int i = 0; i < stations.size(); i++)
            oss << ",,," << stations[i]->getId();
        return oss.str();
    }

    static clsTransportLine parse(string line, OpenHash<int, clsStation*>& stations) {
        DoubleLinkedList<string> tokens = Split(line,",,,");
        if (tokens.size() < 5) {
            throw invalid_argument("Not enough tokens in line");
        }

        int id = stoi(tokens[0]);
        int vehicles = stoi(tokens[1]);
        double price = stod(tokens[2]);
        enVehicleType type = static_cast<enVehicleType>(stoi(tokens[3]));
        string name= tokens[4];
        
        DoubleLinkedList<clsStation*> stationList;
        for (int i = 5; i < tokens.size(); i++) {
            int stationId = stoi(tokens[i]);
            clsStation** station = stations.find(stationId);
            if (station != nullptr) {
                stationList.addLast(*station);
            }
        }

        clsTransportLine tl(id, vehicles, price, type, name, stationList);
        return tl;
    }
};

int clsTransportLine::numberOfAllTransportLines = 0;

#endif // TRANSPORTLINE_H
