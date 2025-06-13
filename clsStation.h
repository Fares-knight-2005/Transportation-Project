#pragma once

#include <iostream>
#include "DataStructures.h"
#include "clsParking.h"
#include "clsVehicle.h"

using namespace std;

string txtFile = "Stations.txt";

class clsStation
{

	int station_id;
	string station_Name;
	ClosedHash <int, clsParking> parkings;
	string city;
	string street;
	int maxParkingsCapicty;
	int maxVehcelNumberIn1Parking;
	enVehicleType stationType;
	bool markToDelete = false;

	string convertObjectToLine(clsStation s)
	{
		string arr[] = {
			to_string(station_id) ,
			station_Name ,
			city ,
			street ,
			to_string(maxParkingsCapicty) , 
			to_string(maxVehcelNumberIn1Parking) ,
			to_string((int)stationType)
		}
		return DataBase::join("#//#");
	}

	//I Need Function in Parking Class return all station Parking

public:

	int getid()
	{
		return station_id;
	}


	void save()
	{
		fstream station;

		station.open(txtFile, ios::out);

		if (station.is_open())
		{
			for (clsStation BaCl : /*from load func*/)
			{
				if (BaCl.markToDelete == false) {
					string Line = convertObjectToLine(BaCl);
					station << Line << endl;
				}
			}

			station.close();
		}
	}


	void Delete()
	{
		markToDelete = true;
	}

};