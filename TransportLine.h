#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "Parking.h"

class TransportLine
{
    public:


    private:
        DoubleLinkedList<Parking> parkings;
        int id,numberOfVehicles;
        double totalLength;
        static int numberOfAllTransportLine;

};
int TransportLine::numberOfAllTransportLine=0;

#endif // TRANSPORTLINE_H
