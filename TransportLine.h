
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
        double totalLength;
        static int numberOfAllTransportLine;

};
int TransportLine::numberOfAllTransportLine=0;


