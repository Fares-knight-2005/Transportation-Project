#include <iostream>
#include <string>

using namespace std;

class Passenger {
private:
    int idStarStation;
    int idEndStation;
    int idPassenger;
    bool isHeadingToEnd;
    bool isDisabled;
    bool hasItems;

public:
    Passenger(int start, int end, int id, bool heading, bool disabled, bool items) {
        idStarStation = start;
        idEndStation = end;
        idPassenger = id;
        isHeadingToEnd = heading;
        isDisabled = disabled;
        hasItems = items;
    }

    int getStartStation() { return idStarStation; }
    int getEndStation() { return idEndStation; }
    int getPassengerId() { return idPassenger; }
    bool getHeadingStatus() { return isHeadingToEnd; }
    bool getDisabilityStatus() { return isDisabled; }
    bool getItemsStatus() { return hasItems; }

    void setStartStation(int start) { idStarStation = start; }
    void setEndStation(int end) { idEndStation = end; }
    void setPassengerId(int id) { idPassenger = id; }
    void setHeadingStatus(bool heading) { isHeadingToEnd = heading; }
    void setDisabilityStatus(bool disabled) { isDisabled = disabled; }
    void setItemsStatus(bool items) { hasItems = items; }

    void displayInfo() {
        cout << "Passenger ID: " << idPassenger << endl;
        cout << "Start Station: " << idStarStation << endl;
        cout << "End Station: " << idEndStation << endl;
        cout << "Heading to end: " << (isHeadingToEnd ? "Yes" : "No") << endl;
        cout << "Disabled: " << (isDisabled ? "Yes" : "No") << endl;
        cout << "Has items: " << (hasItems ? "Yes" : "No") << endl;
    }

    
};
