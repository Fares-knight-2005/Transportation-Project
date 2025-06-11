#ifndef TRANSPORTLINE_H
#define TRANSPORTLINE_H
#include "DataStructures.h"
#include "clsStation.h"

class clsTransportLine
{
    public:

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
