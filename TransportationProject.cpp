
#include <iostream>
#include "clsPerson.h"
#include "clsVehicleDriver.h"
using namespace std;

int main()
{
    clsPerson Me = clsPerson(20 , "Fares" , "Oyion" , "0981883592");
    
    cout << Me.GetFirstName() + " " + Me.GetLastName();
}
