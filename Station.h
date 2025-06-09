#ifndef STATION_H
#define STATION_H
#include "DataStructures.h"
#include "Bus.h"
#include "Passenger.h"

struct ParkingQueue
{
Queue<Bus> buses; // الطابور المخصص بالباصات (مصف)
Queue<Passenger> passengers; // الطابور المخصص بالركاب (ترتيب اولوية الصعود)
};

class Station{

    public:

    bool operator==(int id){
        return this->id==id;
    }
    private:
        ParkingQueue  departure;// المصف المخصص للركاب وباصات المتجيهن الى نهاية الخط
        ParkingQueue  coming;//المصف المخصص للركاب وباصات المتجهين الى بداية الخط
        int id;// معرف الموقف
        static int numberOfAllStation;//عدد الكلي للمواقف
};
int Station::numberOfAllStation=0;

#endif // STATION_H
