#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "Parking.h"

class TransportLine
{
    public:

    bool operator==(int id){
        return this->id==id;
    }
    private:
        DoubleLinkedList<Parking> parkings;
        int id,numberOfVehicles;
        static int numberOfAllTransportLine;

};
int TransportLine::numberOfAllTransportLine=0;

#endif // TRANSPORTLINE_H
