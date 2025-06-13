#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "DataStructures.h"

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

               void saveTransportLines(string filename, OpenHash<int, clsTransportLine>& transportLines) {
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

                OpenHash<int, clsTransportLine> loadTransportLines(const string& filename) {
    
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

           } catch (...) {
              continue; 
           }
           }

            file.close();
            return transportLines;
           }

};

#endif // DATABASE_H
