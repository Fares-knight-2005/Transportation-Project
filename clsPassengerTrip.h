#include<iostream>
using namespace std;

class clsPassengerTrip{
int idStarStation,idEndStation,idPassenger;
bool destination,disability,things;

public:
    clsPassengerTrip(int idStarStation,int idEndStation,int idPassenger):idPassenger(idPassenger),idEndStation(idEndStation),idPassenger(idPassenger) {}
    int getIdEndStation(){
        return idEndStation; 
    }
    bool getDestination(){
        return destination;    
    }
    bool getDisability(){
        return destination;    
    }
    bool getThings(){
        return destination;    
    }
    
};
