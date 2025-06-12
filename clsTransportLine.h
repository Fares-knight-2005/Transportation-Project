#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"

class clsTransportLine
{
    public:
    clsTransportLine(int numberOfVehicles,double pricePerKilometer,enVehicleType vehiclesType,DoubleLinkedList<clsStation> stations):
    stations(stations),pricePerKilometer(pricePerKilometer),id(++numberOfAllTransportLine),vehiclesType(vehiclesType),
    numberOfVehicles(numberOfVehicles)  {}

    clsTransportLine():stations(nullptr),id(0),numberOfVehicles(0),pricePerKilometer(0) {}
/*
    double getDistance(int startId, int endId){
    if(startId>=endId)
        return 0;
    double distance=0;
    for(int i=startId;i>endId;i++)
        //distance+=البعد عن الموقف التالي
        
    return distance;
    }

    double calculateFare(int startId, int endId,bool cardType){
        double distance= getDistance(startId,endId);
        double price=distance*pricePerKilometer;
        if(cardType)
             return price*0.8;
        retrurn price;
    }
*/
    void addStation(clsStation station,int stationNumber){
        stations.add(stationNumber-1,station);   
    }

    void removeStation(int stationId){
       if(stations.remove(stationId))
           cout<<"The deletion process was completed successfully.\n";
       else
           cout<<"The station ID number you entered is not available.\n";
    }

    bool operator==(int id){
        return this->id==id;
    }

    private:
        DoubleLinkedList<clsStation> stations;
        int id,numberOfVehicles,pricePerKilometer;
        enVehicleType vehiclesType;
        static int numberOfAllTransportLine;

};
int clsTransportLine::numberOfAllTransportLine=0;

#endif // TRANSPORTLINE_H
