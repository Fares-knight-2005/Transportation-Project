#ifndef PARKING_H
#define PARKING_H
#include "DataStructures.h"
#include "clsVehicle.h"
#include "clsPassenger.h"

struct strParkingQueue
{
Queue<clsVehicle> vehicle; // الطابور المخصص بالباصات (مصف)
Queue<clsPassenger> passengers; // الطابور المخصص بالركاب (ترتيب اولوية الصعود)
};

class clsParking{

    public:
    clsParking():departure(nullptr),coming(nullptr),id(0) {}

    double getDistanceToNext(){
    return distanceToNext;
    }

    bool operator==(int id){
        return this->id==id;
    }
    private:
        strParkingQueue  departure;// المصف المخصص للركاب وباصات المتجيهن الى نهاية الخط
        strParkingQueue  coming;//المصف المخصص للركاب وباصات المتجهين الى بداية الخط
        int id;// معرف الموقف
        double distanceToNext;//البعد عن الموقف التالي
        static int numberOfAllParking;//عدد الكلي للمواقف
};
int clsParking::numberOfAllParking=0;

#endif // PARKING_H
