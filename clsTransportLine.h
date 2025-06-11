#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"

class clsTransportLine
{
    public:
    clsTransportLine(int numberOfVehicles,DoubleLinkedList<clsStation> stations):
    stations(stations),id(++numberOfAllTransportLine),
    numberOfVehicles(numberOfVehicles)  {}

    clsTransportLine():stations(nullptr),id(0),numberOfVehicles(0) {}

    double calculateFare(int startId, int endId,bool cardType){
        retrurn 0.0;
    }

    
    bool operator==(int id){
        return this->id==id;
    }

    private:
        DoubleLinkedList<clsStation> stations;
        int id,numberOfVehicles;
        static int numberOfAllTransportLine;

};
int clsTransportLine::numberOfAllTransportLine=0;

#endif // TRANSPORTLINE_H
