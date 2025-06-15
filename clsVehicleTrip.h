#include<iostream>
#include "clsPassengerTrip.h"
#include <sstream>

using namespace std;

class clsVehicleTrip {
    struct strVehicleMovements {
        int idStation;
        int currDisabilitSeat, currPackageSize;
        SingleLinkedList<clsPassengerTrip> passengers;

        strVehicleMovements(int idStation) : idStation(idStation), currPackageSize(0), currDisabilitSeat(0) {}
        strVehicleMovements() : idStation(0), currPackageSize(0), currDisabilitSeat(0) {}

        string toString() {
            ostringstream oss;
            oss << idStation;
            
            Node<clsPassengerTrip>* current = passengers.getHead();
            while (current != nullptr) {
                oss << ",,," << current->data.toString();
                current = current->next;
            }
            
            return oss.str();
        }
    };

    int id, numberOfStations, idVehicle, idTransportLine;
    ClosedHash<int, strVehicleMovements> vehicleMovements;
    static int numberOfAllVehicleTrip;

public:
    clsVehicleTrip(int numberOfStations) : 
        id(++numberOfAllVehicleTrip), 
        numberOfStations(numberOfStations),
        idVehicle(0),
        idTransportLine(0) {
        vehicleMovements = ClosedHash<int, strVehicleMovements>(numberOfStations);
    }

    clsVehicleTrip(int id, int numberOfStations) : 
        id(id), 
        numberOfStations(numberOfStations),
        idVehicle(0),
        idTransportLine(0) {
        vehicleMovements = ClosedHash<int, strVehicleMovements>(numberOfStations);          
    }

    int getId() { return id; }
 
    string toString() {
        ostringstream oss;
        oss << id << ",,," << numberOfStations << ",,," << idVehicle << ",,," << idTransportLine;
            
        for(int i = 0; i < vehicleMovements.size(); i++) {
            HashNode<strVehicleMovements> curr = vehicleMovements.getNode(i);
            if (curr.nodeType == ClosedNode<int, strVehicleMovements>::FULL) {
                oss << ",,," << node.item.toString();
            }
        }
        return oss.str();
    }

    void displayInfo() {
        cout << "**************************************\n";
        cout << "       Vehicle Trip Information      \n";
        cout << "**************************************\n";
        cout << "Trip ID: " << id << "\n";
        cout << "TransportLine ID: "<< idTransportLine << "\n";
        cout << "Vehicle ID: "<< idVehicle << "\n";
        cout << "number of stations: " << numberOfStations << "\n\n";

        for (int i = 0; i < vehicleMovements.size(); i++) {
            HashNode<strVehicleMovements> node = vehicleMovements.getNode(i);
            if (node.nodeType == ClosedNode<int, strVehicleMovements>::FULL) {
                cout << "Current Station: " << node.item.idStation << "\n";
                cout << "Passengers List:\n";
                cout << "----------------\n";

                Node<clsPassengerTrip> current = node.item.passengers.getHead();
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

    static clsVehicleTrip parse(string line) {
        DoubleLinkedList<string> tokens = Split(line, ",,,");
        if (tokens.size() < 4) {
            throw invalid_argument("Not enough tokens in line");
        }

        int id = stoi(tokens[0]);
        int numberOfStations = stoi(tokens[1]);
        int idVehicle = stoi(tokens[2]);
        int idTransportLine = stoi(tokens[3]);
        
        clsVehicleTrip trip(id, numberOfStations);
        trip.idVehicle = idVehicle;
        trip.idTransportLine = idTransportLine;
        
        int tokenIndex = 4;
        while (tokenIndex < tokens.size()) {
            int stationId = stoi(tokens[tokenIndex++]);
            strVehicleMovements movement(stationId);
           
            while (tokenIndex + 5 < tokens.size()) {
                try {
                    int start = stoi(tokens[tokenIndex++]);
                    int end = stoi(tokens[tokenIndex++]);
                    int pid = stoi(tokens[tokenIndex++]);
                    bool heading = tokens[tokenIndex++] == "1";
                    bool disabled = tokens[tokenIndex++] == "1";
                    bool items = tokens[tokenIndex++] == "1";
                    
                    clsPassengerTrip passenger(start, end, pid, heading, disabled, items);
                    movement.passengers.addLast(passenger);
                } catch (...) {
                    break;
                }
            }
            
            trip.vehicleMovements.insert(stationId, movement);
        }
        
        return trip;
    }
};

int clsVehicleTrip::numberOfAllVehicleTrip = 0;
