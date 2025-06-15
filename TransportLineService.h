#ifndef TRANSPORTLINESERVICE_H
#define TRANSPORTLINESERVICE_H

#include "clsTransportLine.h"
#include "Database.h"
#include "Input.h"

using namespace std;

class TransportLineService{
public:
    void printAllTransportLines() {
        OpenHash<int, clsTransportLine> transportLines=Database::loadTransportLines(Database::clsTransportLineFileName);

        if (transportLines.isEmpty()) {
            cout << "\nNo Transport Lines Found!\n";
            return;
        }
      
        cout << "\n===========================================\n";
        cout << "        All Transport Lines (" << transportLines.size() << ")";
        cout << "\n===========================================\n"; 


        for (int i = 0; i < transportLines.capacity; i++) {
            HashNode<int,clsTransportLine> *current = transportLines.getHead(i);
            while (current != nullptr) {
                clsTransportLine line = current->data.item;
                line.display();
                current = current->next;
            }
        }
    }


    void addNewTransportLine() {
         OpenHash<int, clsTransportLine> transportLines=Database::loadTransportLines(Database::clsTransportLineFileName);
         OpenHash<int, clsStation> stations=Database::loadStations(Database::clsStationFileName);
      
        cout << "\n===========================================\n";
        cout << "        Add New Transport Line";
        cout << "\n===========================================\n";

        string name = Input::readString("Enter Transport Line Name: ");
        double price = Input::readDouble("Enter Ticket Price: ");
        
        cout << "\nVehicle Types:\n";
        cout << "1. Bus\n";
        cout << "2. Train\n";
        cout << "3. Metro\n";
        
        int typeChoice = Input::ReadIntNumberBetween(1, 4, "Invalid choice. Enter 1-4: ");
        enVehicleType vehicleType = static_cast<enVehicleType>(typeChoice - 1);

      
        DoubleLinkedList<clsStation> lineStations;
        if (!stations.isEmpty()) {
            cout << "\nAvailable Stations:\n";
            for (int i = 0; i < stations.capacity; i++) {
                DoubleNode<clsStation> current = stations.getHead(i);
                while (current != nullptr) {
                    cout << current->data.item.getId() << " - " << current->data.item.getName() << endl;
                    current = current->next;
                }
            }

            bool addMore = Input::readBool("Are there any stations to add? (yes/no): ","yes","no");
            while (addMore) {
                int stationId = Input::readInt("Enter Station ID to add to line: ");
                clsStation* station = stations[stationId];
                if (station != nullptr) {
                    lineStations.addLast(*station);
                    cout << "Station added successfully.\n";
                } else {
                    cout << "Station not found!\n";
                }
                addMore = Input::readBool("Add another station? (yes/no): ","yes","no");
            }
        }

        clsTransportLine newLine(price, vehicleType, name, lineStations);
        transportLines.insert(newLine.getId(), newLine);

        cout << "\nTransport Line added successfully with ID: " << newLine.getId() << "\n";
        Database::saveTransportLines(Database::clsTransportLineFileName, transportLines);
    }


};


#endif // TRANSPORTLINESERVICE_H
