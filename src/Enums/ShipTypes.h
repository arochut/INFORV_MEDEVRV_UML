#include <string>

#ifndef ShipTypes_H
#define ShipTypes_H

using namespace std;

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
        static const ShipType SHIP_TYPES[7];

    
};

struct ShipType {
    string name;
    int size; 
};

#endif // ShipTypes_H
