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

                statOpenHash<int, clsTransportLine> loadTransportLines(const string& filename) {
    
                OpenHash<int, clsTransportLine> transportLines;
	        OpenHash<int,clsStation> stations;//يجب تحميله من تابع staions
		    
                ifstream file(filename);
                string line;

                while (getline(file, line)) {
                  try {
                   DoubleLinkedList<string>  tokens = Split(line, ",,,");
                    if (tokens.size() < 4) 
			    continue;
              int id = stoi(tokens[0]);
              int vehicles = stoi(tokens[1]);
              double price = stod(tokens[2]);
              enVehicleType type = static_cast<enVehicleType>(stoi(tokens[3]));
              DoubleLinkedList<clsStation> s;
              for (int i = 4; i < tokens.size(); i++) {
                  int stationId = stoi(tokens[i]);
                  s.addFirst(stations[stationId]);
                }
              }

            clsTransportLine tl(vehicles, price, type, s);
            tl.setid(id);
            transportLines.insert(id, tl);
	    if(clsParking::numberOfAllTransportLine<id)
		    clsParking::numberOfAllTransportLine=id;

           } catch (...) {
              continue; 
           }
           }

            file.close();
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
            DoubleLinkedList<string> tokens = Split(line, ",,,");
            if (tokens.size() < 4) 
		    continue;

            int id = stoi(tokens[0]);
            int stationId = stoi(tokens[1]);
            double distance = stod(tokens[2]);
            enVehicleType type = static_cast<enVehicleType>(stoi(tokens[3]));

            clsParking parking(id, distance,stationId,type);
            
            parkings.insert(id, parking);
	    if(clsParking::numberOfAllParking<id)
		    clsParking::numberOfAllVehicle=id;

        } catch (...) {
            continue;
        }
    }

    file.close();
    return parkings;
}

};




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
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        try {
            DoubleLinkedList<string> tokens = Split(line, ",,,");
            if (tokens.size() < 7)
		    continue;

            enVehicleType type = static_cast<enVehicleType>(stoi(tokens[0]));
            int lineId = stoi(tokens[1]);
            int cap = stoi(tokens[2]);
            float spd = stof(tokens[3]);
            int disabilitySeats = stoi(tokens[4]);
            int pkgSize = stoi(tokens[5]);
            int id= stoi(tokens[6]);
            clsVehicle vehicle(id,type, lineId, cap, spd, disabilitySeats, pkgSize);
            
            for (int i = 7; i < tokens.size(); i++) {
                vehicle.vehicleTripId.addLast(stoi(tokens[i]));
            }
            
            vehicles.insert(id,vehicle);
	    if(clsVehicle::numberOfAllVehicle<id)
		    clsVehicle::numberOfAllVehicle=id;
		
        } catch (...) {
            continue;
        }
    }

    file.close();
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
                DoubleLinkedList<string> tokens = Split(line, ",,,");
                if (tokens.size() < 8) 
			continue;

                int id = stoi(tokens[0]);
                short age = stoi(tokens[1]);
                string firstName = tokens[2];
                string lastName = tokens[3];
                string phoneNumber = tokens[4];
                string email = tokens[5];
                
                bool cardType = (tokens[6] == "Premium");
                double cardBalance = stod(tokens[7]);
                clsCard card(cardType, cardBalance);
                
                clsPassenger passenger(age, firstName, lastName, phoneNumber, email, id, card);
                
                passengers.insert(id, passenger);
                
                if(numberOfAllPassenger < id)
                    numberOfAllPassenger = id;
                
            } catch (...) {
                continue;
            }
        }

        file.close();
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

#endif // DATABASE_H
