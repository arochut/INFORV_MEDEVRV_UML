
#ifndef ShipTypes_H
#define ShipTypes_H

#include <string>
using namespace std;

struct ShipType {
    string name;
    int size; 
};

class ShipTypes
{
    
    public:
        static const ShipType BATTLESHIP;
        static const ShipType CRUISER;
        static const ShipType DESTROYER;
        static const ShipType SUBMARINE_1;
        static const ShipType SUBMARINE_2;
        static const ShipType FISHING_1;
        static const ShipType FISHING_2;
        static const int SHIP_COUNT = 7;
        static const ShipType SHIP_TYPES[SHIP_COUNT];

    
};

#endif // ShipTypes_H
