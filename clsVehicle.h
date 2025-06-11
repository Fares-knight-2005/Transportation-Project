#include <iostream>
#include "clsPerson.h"
#include "DataStructures.h"

using namespace std;

        enum enVehicleType {BUS=1, TRAM, FERRY, METRO};

       string getVehicleType(enVehicleType vehicleType) {
       switch(vehicleType) {
        case BUS:  return "BUS";
        case TRAM: return "TRAM";
        case FERRY: return "FERRY";
        default: return "METRO";
       }
       }

       enVehicleType setVehicleType(int vehicleNumber){
       switch(vehicleNumber){
       case 1:return BUS;
       case 2:return TRAM;
       case 3:return FERRY;
       default:return METRO;
       }
       }

       class clsVehicle{
       public:






       private:
       enVehicleType vehicleType;
       



        };

      
