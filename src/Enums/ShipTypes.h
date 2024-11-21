#include <string>

#ifndef ShipTypes_H
#define ShipTypes_H
class ShipTypes
{
    
    public:
        static const ShipType BATTLESHIP = {"Battleship", 5};
        static const ShipType CRUISER = {"Cruiser", 4};
        static const ShipType DESTROYER = {"Destroyer", 3};
        static const ShipType SUBMARINE_1 = {"Submarine 1", 2};
        static const ShipType SUBMARINE_2 = {"Submarine 2", 2};
        static const ShipType FISHING_1 = {"Fishing 1", 1};
        static const ShipType FISHING_2 = {"Fishing 2", 1};
        static const ShipType[] SHIP_TYPES = {BATTLESHIP, CRUISER, DESTROYER, SUBMARINE_1, SUBMARINE_2, FISHING_1, FISHING_2};

    
};

struct ShipType {
    string name;
    int size; 
}

#endif // ShipTypes_H
