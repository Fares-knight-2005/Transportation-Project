#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include "DataStructures.h"
#include "clsVehicle.h"
#include "clsParking.h"
#include "clsTransportLine.h"
#include "clsVehicleTrip.h"
#include "clsPassenger.h"

class Database
{
public:

static string clsVehicleFileName,clsParkingFileName;
static string clsTransportLineFileName,clsVehicleTripFileName;
static string clsPassengerFileName;


static DoubleLinkedList <string> Split(string s, string delim)
{
string Word = "";

DoubleLinkedList <string> Words;

short pos = s.find(delim);

while (pos != string::npos)
{
Word = s.substr(0, pos);
s.erase(0, pos + delim.length());

if (Word != "")
    Words.addLast(Word);
    pos = s.find(delim);
}

if (s != "")
   Words.addLast(s);

  return Words;
}



static string JoinString(string* ArrString, string Delim)
{
string Results = "";

for (int i = 0; i < ArrString->length; i++)
{
Results += Delim + ArrString[i];
}

return Results.substr(Delim.length(), Results.length() - Delim.length());
}

static void saveTransportLines(string filename, OpenHash<int, clsTransportLine>& transportLines) {
    ofstream outFile(filename);
    
    for (int i = 0; i < transportLines.capacity; i++) {
         HashNode<clsTransportLine>* current = transportLines.array[i].getHead();
         while (current != nullptr) {
                outFile << current->data.item.toString() << endl;
                current = current->next;
          }
          }
        outFile.close();
 }

static OpenHash<int, clsTransportLine> loadTransportLines(string filename) {
    OpenHash<int, clsTransportLine> transportLines;
    OpenHash<int, clsStation> stations=loadTransportLines("station");
    
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsTransportLine tl =clsTransportLine::parse(line, stations);
            transportLines.insert(tl.getid(), tl);
            
            if (clsParking::getNumberOfAllTransportLine() < tl.getId()) {
                clsParking::setNumberOfAllTransportLine(tl.getId());
            }
        } catch (...) {
            continue;
        }
    }
    
    return transportLines;
}

static void saveParkings(string& filename, OpenHash<int, clsParking>& parkings) {
    ofstream outFile(filename);
    
    for (int i = 0; i < parkings.capacity; i++) {
        DoubleLinkedList<clsParking> *current = parkings.array[i].getHead();
        while (current != nullptr) {
            outFile << current->data.item.toString() << endl;
            current = current->next;
        }
    }
    
    outFile.close();
}


static OpenHash<int, clsParking> loadParkings(string filename) {
    OpenHash<int, clsParking> parkings;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsParking parking =clsParking::parse(line);
            parkings.insert(parking.getId(), parking);
            
            if (clsParking::getNumberOfAllParking() < parking.getId()) {
                clsParking::setNumberOfAllParking(parking.getId());
            }
        } catch (...) {
            continue;
        }
    }

    return parkings;
}



static void saveVehicles(string& filename, OpenHash<int, clsVehicle>& vehicles) {
    ofstream outFile(filename);
    
    for (int i = 0; i < vehicles.capacity; i++) {
        HashNode<int, clsVehicle> *current = vehicles.array[i].getHead();
        while (current != nullptr) {
            outFile << current->data.item.toString() << endl;
            current = current->next;
        }
    }
    
    outFile.close();
}

static OpenHash<int, clsVehicle> loadVehicles(string filename) {
    OpenHash<int, clsVehicle> vehicles;
    OpenHash<int, clsVehicleTrip> vehicleTrip=loadVehicleTrips(Database::clsVehicleTripFileName);
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsVehicle vehicle =clsVehicle::parse(line,vehicleTrip);
            vehicles.insert(vehicle.getId(), vehicle);
            
            if (clsVehicle::getNumberOfAllVehicle() < vehicle.getId()) {
                clsVehicle::setNumberOfAllVehicle(vehicle.getId());
            }
        } catch (...) {
            continue;
        }
    }

    return vehicles;
}

template<class Item>
static void savePassengers(string& filename, OpenHash<Item, clsPassenger>& passengers) {
     ofstream outFile(filename);
        
     for (int i = 0; i < passengers.capacity; i++) {
            HashNode<<Item, clsPassenger> *current = passengers.array[i].getHead();
            while (current != nullptr) {
                outFile << current->data.item.toString() << endl;
                current = current->next;
            }
        }
        
        outFile.close();
}

static OpenHash<int, clsPassenger> loadPassengers(string filename) {
    OpenHash<int, clsPassenger> passengers;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsPassenger passenger =clsPassenger::parse(line);
            passengers.insert(passenger.getId(), passenger);
            
            if (clsPassenger::getNumberOfAllPassenger() < passenger.getId()) {
                clsPassenger::setNumberOfAllPassenger(passenger.getId());
            }
        } catch (...) {
            continue;
        }
    }

    return passengers;
}

static OpenHash<string, clsPassenger> loadPassengersByName(string filename) {
    OpenHash<string, clsPassenger> passengers;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsPassenger passenger = clsPassenger::parse(line);
            string fullNameKey = passenger.GetFullName();
            passengers.insert(fullNameKey, passenger);
            
            if (clsPassenger::getNumberOfAllPassenger() < passenger.getId()) {
                clsPassenger::setNumberOfAllPassenger(passenger.getId());
            }
        } catch (...) {
            continue;
        }
    }

    return passengers;
}

static void saveVehicleTrips(const string& filename, OpenHash<int, clsVehicleTrip>& trips) {
    ofstream outFile(filename);
    
    for (int i = 0; i < trips.capacity; i++) {
        HashNode<int, clsVehicleTrip> *current = trips.getHead(i);
        while (current != nullptr) {
            outFile << current->data.item.toString() << endl;
            current = current->next;
        }
    }
    
    outFile.close();
}

static OpenHash<int, clsVehicleTrip> loadVehicleTrips(const string& filename) {
    OpenHash<int, clsVehicleTrip> trips;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsVehicleTrip trip =clsVehicleTrip::parse(line);
            trips.insert(trip.getId(), trip);
            
            if (clsVehicleTrip::getNumberOfAllVehicleTrip() < trip.getId()) {
                clsVehicleTrip::setNumberOfAllVehicleTrip(trip.getId());
            }
        } catch (...) {
            continue;
        }
    }

    return trips;
    }

};
static string Database::clsVehicleFileName="vehicle";
static string Database::clsParkingFileName="parking";
static string Database::clsTransportLineFileName="transportLine";
static string Database::clsVehicleTripFileName="vehicleTrip";
static string Database::clsPassengerFileName="passenger";

#endif // DATABASE_H
