#ifndef PARKING_H
#define PARKING_H
#include "DataStructures.h"
#include "Bus.h"
#include "Passenger.h"

struct strParkingQueue
{
Queue<Bus> buses; // الطابور المخصص بالباصات (مصف)
Queue<Passenger> passengers; // الطابور المخصص بالركاب (ترتيب اولوية الصعود)
};

class clsParking{

    public:

    bool operator==(int id){
        return this->id==id;
    }
    private:
        strParkingQueue  departure;// المصف المخصص للركاب وباصات المتجيهن الى نهاية الخط
        strParkingQueue  coming;//المصف المخصص للركاب وباصات المتجهين الى بداية الخط
        int id;// معرف الموقف
        static int numberOfAllParking;//عدد الكلي للمواقف
};
int clsParking::numberOfAllParking=0;

#endif // PARKING_H
