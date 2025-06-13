#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include "DataStructures.h"
#include "clsVehicle"
#include "clsParking.h"
#include "clsTransportLine.h"

class Database
{
    public:


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
                 HashNode<clsTransportLine> current = transportLines.array[i].getHead();
                 while (current != nullptr) {
                      outFile << current->data.item.toString() << endl;
                      current = current->next;
                }
                }
    
                outFile.close();
                }

static OpenHash<int, clsTransportLine> loadTransportLines(string filename) {
    OpenHash<int, clsTransportLine> transportLines;
    OpenHash<int, clsStation> stations;//هون في تابع
    
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsTransportLine tl =clsTransportLine.parse(line, stations);
            transportLines.insert(tl.getid(), tl);
            
            if (clsParking::numberOfAllTransportLine < tl.getId()) {
                clsParking::numberOfAllTransportLine = tl.getId();
            }
        } catch (...) {
            continue;
        }
    }
    
    return transportLines;
}

static void saveParkings(const string& filename, OpenHash<int, clsParking>& parkings) {
    ofstream outFile(filename);
    
    for (int i = 0; i < parkings.capacity; i++) {
        DoubleLinkedList<clsParking> current = parkings.array[i].getHead();
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
            clsParking parking = parse(line);
            parkings.insert(parking.getId(), parking);
            
            if (clsParking::numberOfAllParking < parking.getId()) {
                clsParking::numberOfAllParking = parking.getId();
            }
        } catch (...) {
            continue;
        }
    }

    return parkings;
}



static void saveVehicles(const string& filename, OpenHash<int, clsVehicle>& vehicles) {
    ofstream outFile(filename);
    
    for (int i = 0; i < vehicles.capacity; i++) {
        auto current = vehicles.array[i].getHead();
        while (current != nullptr) {
            outFile << current->data.item.toString() << endl;
            current = current->next;
        }
    }
    
    outFile.close();
}

static OpenHash<int, clsVehicle> loadVehicles(string filename) {
    OpenHash<int, clsVehicle> vehicles;
    OpenHash<int, clsVehicleTrip> vehicleTrip=loadVehicleTrips();// اسم الملف
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            clsVehicle vehicle = parseVehicle(line,vehicleTrip);
            vehicles.insert(vehicle.getId(), vehicle);
            
            if (clsVehicle::numberOfAllVehicle < vehicle.getId()) {
                clsVehicle::numberOfAllVehicle = vehicle.getId();
            }
        } catch (...) {
            continue;
        }
    }

    return vehicles;
}

    static void savePassengers(const string& filename, OpenHash<int, clsPassenger>& passengers) {
        ofstream outFile(filename);
        
        for (int i = 0; i < passengers.capacity; i++) {
            auto current = passengers.array[i].getHead();
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
            clsPassenger passenger = parse(line);
            passengers.insert(passenger.getId(), passenger);
            
            if (clsPassenger::numberOfAllPassenger < passenger.getId()) {
                clsPassenger::numberOfAllPassenger = passenger.getId();
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
        HashNode<int, clsVehicleTrip> current = trips.getHead(i);
        while (current != nullptr) {
            outFile << current->data.item.toString() << endl;
            current = current->next;
        }
    }
    
    outFile.close();
}

static OpenHash<int, clsVehicleTrip> loadVehicleTrips(string filename) {
    OpenHash<int, clsVehicleTrip> trips;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            DoubleLinkedList<string> tokens = Split(line, ",,,");
            if (tokens.size() < 2) 
                continue;

            int id = stoi(tokens[0]);
           
            
            clsVehicleTrip trip(id);
            
            int tokenIndex = 1;
            while (tokenIndex < tokens.size()) {
                int stationId = stoi(tokens[tokenIndex++]);
                
                strVehicleMovements movement(stationId);
               
                while (tokenIndex < tokens.size()) {
                    try {
                        int start = stoi(tokens[tokenIndex++]);
                        int end = stoi(tokens[tokenIndex++]);
                        int pid = stoi(tokens[tokenIndex++]);
                        bool heading = tokens[tokenIndex++] == "1";
                        bool disabled = tokens[tokenIndex++] == "1";
                        bool items = tokens[tokenIndex++] == "1";
                        
                        clsPassengerTrip passenger(start, end, pid, heading, disabled, items);
                        movement.passenger.addLast(passenger);
                    } catch (...) {
                        break;
                    }
                }
                
                trip.vehicleMovements.insert(stationId, movement);
            }
            
            trips.insert(id, trip);
            
            if(clsVehicleTrip::numberOfAllVehicleTrip < id)
                clsVehicleTrip::numberOfAllVehicleTrip = id;
                
        } catch (...) {
            continue;
        }
    }

    file.close();
    return trips;
   }
};
#endif // DATABASE_H
