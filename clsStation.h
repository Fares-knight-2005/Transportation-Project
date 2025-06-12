#pragma once

#include <iostream>
#include "DataStructures.h"
#include "clsParking.h"
#include "clsVehicle.h"

using namespace std;

class clsStation
{

	int station_id;
	string stationName;
	ClosedHash <int, clsParking> parkings;
	string city
	string street;
	int maxParkingsCapicty;
	int maxVehcelNumberIn1Parking;
	enVehicleType stationType;


public:


};